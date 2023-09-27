#include <iostream>
#define MOD 1000000007

using namespace std;
using ll = long long;

ll N, A[1005];

ll phi(ll x) {
    ll ret = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
            }
            ret -= ret / i;
        }
    }
    if (x > 1) {
        ret -= ret / x;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> N;
        ll ret = 1;
        for (int i = 1; i <= N; i++) {
            int x;
            cin >> x;
            ret = (ret * phi(x)) % MOD;
        }
        cout << ret << "\n";
    }
    return 0;
}