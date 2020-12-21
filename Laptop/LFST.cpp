#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int dp[40000][182][4];
int dfs(int n, int pre_Val, int used)
{
	if (n == 0)return 1;

	if (used == 4 || pre_Val == 182)return 0;

	int &ret = dp[n][pre_Val][used];

	if (ret != -1)return ret;

	ret = dfs(n, pre_Val + 1, used);

	if (n >= pre_Val * pre_Val)ret += dfs(n - pre_Val * pre_Val, pre_Val, used + 1);

	return ret;
}
int main()
{
	while (true)
	{
		memset(dp, -1, sizeof(dp));

		int n;

		cin >> n;

		if (!n)break;

		cout << dfs(n, 1, 0) << '\n';
	}
	return 0;
}