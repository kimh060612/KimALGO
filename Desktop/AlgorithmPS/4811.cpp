#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

int N;
ll DP[31][31];

ll pill(ll w, ll h)
{
	if (h < 0) return 0;
	if (w == 0 || h == N) return 1;
	if (DP[w][h] != 0) return DP[w][h];
	
	return DP[w][h] = pill(w, h - 1) + pill(w - 1, h + 1);
}

int main()
{
	while (1)
	{
		cin >> N;
		if (N == 0) break;
		memset(DP, 0, sizeof(DP));
		ll ans = pill(N, 0);
		cout << ans << endl;
	}
	return 0;
}