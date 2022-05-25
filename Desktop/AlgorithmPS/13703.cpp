#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

ll DP[65 * 3][65];
ll k, n;

ll dfs(ll now, ll depth)
{
	ll &ret = DP[now][depth];
	if (ret != -1) return ret;

	if (now == 0) return 0;
	if (depth == 0) return 1;

	ret = dfs(now - 1, depth - 1) + dfs(now + 1, depth - 1);
	return ret;
}

int main()
{
	cin >> k >> n;
	memset(DP, -1, sizeof(DP));

	cout << dfs(k, n) << endl;

	return 0;
}