#include <iostream>
#define INF 987654321

using namespace std;

int min(int a, int b)
{
	return a > b ? b : a;
}

int main()
{
	int case_num;
	cin >> case_num;

	for (int i = 1; i <= case_num; i++)
	{
		int num, DATA[501] = {0,};
		int DP[501][501] = {0,};
		int sum[501] = { 0, };
		cin >> num;
		for (int j = 1; j <= num; j++)
		{
			cin >> DATA[j];
			sum[j] = sum[j - 1] + DATA[j];
		}

		for (int d = 1; d < num; d++)
		{
			for (int j = 1; j + d <= num; j++)
			{
				int l = j + d;
				DP[j][l] = INF;
				for (int k = j; k <= l; k++)
				{
					DP[j][l] = min(DP[j][l], DP[j][k] + DP[k + 1][l] + sum[l] - sum[j - 1]);
				}
			}
		}

		cout << DP[1][num] << endl;
	}

	return 0;
}