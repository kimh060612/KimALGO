#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#define MAX 1000000
#define HMAX 500000

using namespace std;
using ll = long long;
using base = complex<double>;
using vec = vector<base>;

vector<ll> prime, RP, SP;

void fft(vec &a, bool inv) {
    int n = (int) a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }
    for (int i = 1; i < n; i <<= 1) {
        double x = inv ? M_PI / i : -M_PI / i;
        base w = {cos(x), sin(x)};
        for (int j = 0; j < n; j += i << 1) {
            base th = {1, 0};
            for (int k = 0; k < i; k++) {
                base tmp = a[i + j + k] * th;
                a[i + j + k] = a[j + k] - tmp;
                a[j + k] += tmp;
                th *= w;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}

void multiply(vec &a, vec &b, vec &c, vec &r) {
    int n = (int) max(a.size(), b.size());
    int i = 0;
    while ((1 << i) < (n << 1)) i++;
    n = 1 << i;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    fft(a, false);
    fft(b, false);
    r.assign(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
        r[i] = r[i] * r[i] * r[i];
    }
    fft(c, true);
    fft(r, true);
}

void init() {
    prime.resize(MAX + 5);
    fill(prime.begin(), prime.end(), 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i * i <= MAX; i++) {
        if (!prime[i]) continue;
        for (int j = 2 * i; j <= MAX; j += i) {
            prime[j] = 0;
        }
    }

    vec P, Q, R, S;
    P.resize(MAX + 5);
    Q.resize(MAX + 5);
    for (int i = 3; i <= MAX; i++) {
        if (prime[i]) {
            P[(i - 1) / 2] = base(1., 0.);
            if (i - 1 < HMAX) Q[i - 1] = base(1., 0.);
        }
    }
    multiply(P, Q, S, R);
    RP.resize(MAX + 5);
    SP.resize(MAX + 5);
    for (int i = 0; i <= MAX; i++) {
        RP[i] = (ll)(R[i].real() + (R[i].real() > 0 ? 0.5 : -0.5));
        SP[i] = (ll)(S[i].real() + (S[i].real() > 0 ? 0.5 : -0.5));
    }
}

ll getVal(int n) {
    int index = (n - 3) / 2;
    ll ret = 0;
    if (n % 3 == 0 && prime[n / 3]) {
        ret = (RP[index] - 3 * SP[index] + 2) / 6 + SP[index];
    } else {
        ret = (RP[index] - 3 * SP[index]) / 6 + SP[index];
    }
    return ret + prime[n - 4];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cout << getVal(N) << "\n";
    }
    return 0;
}