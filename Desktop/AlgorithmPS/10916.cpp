#include <iostream>
#define MOD 1000000007
#define MAX 1000010

using namespace std;
using ll = long long;

ll N, B[10001], A[10001], PB[10001], PA[10001], mB = MOD, ret = 1;
ll dX[MAX], dY[MAX], mInv[MAX];
int mu[MAX], phi[MAX];

ll min(ll a, ll b) { return a < b ? a : b; }

ll fpow(ll a, ll n) {
    ll ret = 1;
    while (n) {
        if (n % 2 == 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return ret;
}

void Init() {
    mu[1] = 1;
    for(int i = 1; i <= MAX; i++) {
        for(int j = 2 * i; j <= MAX; j += i) {
            mu[j] -= mu[i];
        }
    }
    for (int k = 1; k <= MAX; k++) {
        for (int d = 1; d * d <= k; d++) {
            if (k % d == 0) {
                phi[k] = (phi[k] + d * mu[k / d]) % MOD;
                if (d != k / d) phi[k] = (phi[k] + (k / d) * mu[d]) % MOD;
            }
        }
    }
    for (int i = 1; i <= MAX; i++) {
        mInv[i] = fpow(i, MOD - 2);
        dX[i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        PB[i] = B[i];
        PA[i] = A[i];
        mB = min(mB, B[i]);
        ret = (ret * (B[i] - A[i])) % MOD;
    }
    Init();

    for (int i = 1; i <= N; i++) {
        // cout << i << ": ";
        for (int k = 1; k <= B[i];) {
            ll skip = MOD + 1;
            if (PA[i] != PB[i]) dX[k] = (dX[k] * mInv[PB[i] - PA[i]]) % MOD;
            else dY[k] -= 1;

            ll bBi = B[i] / k, bAi = A[i] / k;
            if (bBi != bAi) dX[k] = (dX[k] * (bBi - bAi)) % MOD;
            else dY[k] += 1;

            if (A[i] >= k) skip = min(skip, A[i] / bAi);
            skip = min(skip, B[i] / bBi);

            PA[i] = bAi;
            PB[i] = bBi;
            // cout << k << " ";
            k = skip + 1;
        }
        // cout << "\n";
    }

    ll cnt = 0, ans = 0;
    for (int k = 1; k <= mB; k++) {
        ret = (ret * dX[k]) % MOD;
        cnt += dY[k];
        if (cnt == 0) {
            ans = (ans + ret * phi[k]) % MOD;
        }
    }
    cout << ans << "\n";
    return 0;
}