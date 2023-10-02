#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
#include <cmath>
#define MAX 1000000
#define HMAX 500000

using namespace std;
using base = complex<double>;
using vec = vector<base>;

vector<int> prime;
vec ret;

int max(int a, int b) { return a > b ? a : b; }

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

void multiply(vec &a, vec &b, vec &c) {
    int n = (int) max(a.size(), b.size());
    int i = 0;
    while ((1 << i) < (n << 1)) i++;
    n = 1 << i;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] * b[i];
    }
    fft(c, true);
}

void init() {
    prime.resize(MAX + 1);
    fill(prime.begin(), prime.end(), 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i] == 0) continue;
        for (int j = 2 * i; j <= MAX; j += i) {
            prime[j] = 0;
        }
    }

    vec tmp1, tmp2;
    tmp1.resize(HMAX + 2);
    tmp2.resize(HMAX + 2);
    for (int i = 0; i <= MAX; i++) {
        if (prime[i] && i != 2) {
            tmp1[(i - 1) / 2] = base(1., 0.);
            tmp2[(i - 1) / 2] = base(1., 0.);
        }
    }
    multiply(tmp1, tmp2, ret);
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
        if(N == 4) cout << 1 << '\n';
        else cout << ceil(round(ret[N / 2 - 1].real()) / 2) << "\n";
    }
    return 0;
}