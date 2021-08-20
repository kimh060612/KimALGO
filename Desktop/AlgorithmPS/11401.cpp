#include <iostream>
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll N, K;

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int main()
{
    cin >> N >> K;

    ll A = 1, B = 1;
    for (int i = 1; i <= K; i++) A = (A * (N - i + 1)) % MOD;
    for (int i = 1; i <= K; i++) B = (B * i) % MOD;

    ll ans = (A * (binpow(B, MOD - 2)))% MOD;
    cout << ans << endl;
    return 0;
}