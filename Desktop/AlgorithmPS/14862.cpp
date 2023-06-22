#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
using ll = long long;
using iiip = pair<ll, pair<ll, ll>>;

int K, A[10], B[10];
int mu[200010], phi[200010];

int min(int a, int b) { return a < b ? a : b; }

void Init() {
    mu[1] = 1;
    for(int i = 1; i <= 200010; i++) {
        for(int j = 2 * i; j <= 200010; j += i) {
            mu[j] -= mu[i];
        }
    }
    for (int k = 1; k <= 200000; k++) {
        for (int d = 1; d * d <= k; d++) {
            if (k % d == 0) {
                phi[k] = (phi[k] + d * mu[k / d]) % MOD;
                if (d != k / d) phi[k] = (phi[k] + (k / d) * mu[d]) % MOD;
            }
        }
    }
}

iiip xGCD(ll a, ll b) {
    if(b == 0) return { a, { 1 , 0 } };
    iiip ret = xGCD(b, a%b);
    int g, x, y;
    g = ret.first;
    x = ret.second.first; y = ret.second.second;
    return { g, { y, x - (a / b) * y } };
}

ll mod_inverse(ll a) {
    iiip res = xGCD(a, MOD);
    if(res.first > 1) return -1;
    return (res.second.first + MOD) % MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    Init();
    while (t--) {
        cin >> K;
        for (int i = 1; i <= K; i++) cin >> A[i] >> B[i];
        ll P = 0, Q = 1, QI, mB = 200010;
        for (int i = 1; i <= K; i++) Q = (Q * (ll)(B[i] - A[i] + 1)) % MOD;
        for (int i = 1; i <= K; i++) mB = min(mB, B[i]);
        QI = mod_inverse(Q);
        if (QI == -1) {
            cout << -1 << "\n";
            continue;
        }
        for (int k = 1; k <= mB; k++) {
            ll coeff = 1;
            for (int i = 1; i <= K; i++) {
                coeff = (coeff * ((B[i] / k) - ((A[i] - 1) / k))) % MOD;
            }
            P = (P + (coeff * phi[k]) % MOD) % MOD;
        }
        ll N = (MOD - (P * QI) % MOD) % MOD;
        cout << N << "\n";
    }
}