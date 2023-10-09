#include <iostream>
#include <cmath>
#define MAX 4000000
#define MOD 1073741824

using namespace std;
using ll = unsigned long long;

ll N, M, f[MAX + 5], sF[MAX + 5];
int mu[MAX + 5];

void swap(ll &a, ll &b) {
    ll tmp = a;
    a = b;
    b = tmp;
}
ll min(ll a, ll b) { return a < b ? a : b; }
int Abs(int x) { return x < 0 ? -x : x; }
void init() {
    mu[1] = 1;
    for(int i = 1; i <= MAX; i++) {
        for(int j = 2 * i; j <= MAX; j += i) {
            mu[j] -= mu[i];
        }
    }

    for(int i = 1; i <= MAX; i++) {
        for(int j = i; j <= MAX; j += i) {
            f[j] = (f[j] + mu[i] * i * Abs(mu[j / i])) % MOD;
        }
    }
    for(int i = 1; i <= MAX; i++) f[i] = (f[i] * i) % MOD;
    for(int i = 1; i <= MAX; i++) sF[i] = (f[i] + sF[i - 1]) % MOD;
}

ll prod(ll x) {
    return (x * (x + 1) / 2) % MOD;
}

ll getLCMSum(ll n, ll m) {
    ll ret = 0;
    ll i, la = 0;
    for (i = 1; i <= n; i = la + 1) {
        la = min(n / (n / i), m / (m / i));
        ret = (ret + (prod(n / i) * prod(m / i) * (sF[la] - sF[i - 1]))) % MOD;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    init();
    while (t --) {
        cin >> N >> M;
        if (N > M) swap(N, M);
        cout << getLCMSum(N, M) << "\n";
    }
    return 0;
}