#include<iostream>
using namespace std;

const int MY_INT_MAX = 2000000000;
int dp[1000000] = { 0 };
int dp_2[1000000] = { 0 };

int max(int a, int b) { return a > b ? a : b; }

void solution()
{
	// code
	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	int now_idx = 2;
	while (dp[now_idx] <= n)
	{
		++now_idx;
		dp[now_idx] = dp[now_idx - 1] + dp[now_idx - 2];
	}
	int min_output = 0;
	int max_output = 0;
	int tmp_c = n;
	if (tmp_c % 2 == 1)
	{
		tmp_c -= 3;
		min_output += 2;
	}
	min_output += tmp_c / 2;
	tmp_c = n;
	dp_2[2] = 1;
	dp_2[3] = 2;
	dp_2[4] = 2;
	dp_2[5] = 3;
	dp_2[6] = 4;

	for (int i = 7; i <= n; i++)
	{
		int now_max = -1;
		int tmp_idx = 2;
		while (dp[tmp_idx] <= i)
		{
			now_max = max(now_max, dp_2[dp[tmp_idx]] + dp_2[i - dp[tmp_idx]]);
			tmp_idx++;
		}
		dp_2[i] = now_max;
	}
	cout << min_output << " " << dp_2[n];

}

int main()
{
	iostream::sync_with_stdio(0); 
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}