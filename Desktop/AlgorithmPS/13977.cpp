#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;
using ll = long long;

ll fact[4000001];

ll fpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n, k;
    cin >> m;
    fact[0] = 1;
    for (int i = 1; i <= 4000000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    for (int i = 1; i <= m; i++) {
        cin >> n >> k;
        ll tmp = (fact[k] * fact[n - k]) % MOD;
        ll ans = (fact[n] * fpow(tmp, MOD - 2)) % MOD;
        cout << ans << '\n';
    }
    return 0;
}