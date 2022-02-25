#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[301][30];
int DP[30][301], M[30][301];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		for (int j = 1; j <= m; j++) cin >> A[i][j];
	}

	for (int j = 1; j <= m; j++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int k = 0; k <= i; k++)
			{
				int tmp = DP[j - 1][i - k] + A[k][j];
				if (tmp > DP[j][i]) {
					DP[j][i] = tmp;
					M[j][i] = k;
				}
			}
		}
	}

	cout << DP[m][n] << endl;
	int curr = m;
	int cost = n;
	vector<int> ans;
	while (curr > 0)
	{
		int now_ = M[curr][cost];
		ans.push_back(now_);
		cost -= now_;
		curr--;
	}
	reverse(ans.begin(), ans.end());
	for (auto x : ans) cout << x << " ";
	cout << endl;
	return 0;
}