#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;
using ll = long long;

int n, A[300001];
ll ans = 0;

ll fpow(ll a, ll b)
{
    ll res = 1;
    while (b) {
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

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + 1 + n);
    for (int i = 1; i <= n; i++) 
    {
        ll max_2 = fpow(2, i - 1);
        ll min_2 = fpow(2, n - i);
        ans += ((ll)(A[i] % MOD) * (max_2 % MOD)) % MOD;
        ans -= ((ll)(A[i] % MOD) * (min_2 % MOD)) % MOD;
        ans = (ans % MOD + MOD) % MOD;
    }

    cout << ans << endl;
    return 0;
}