#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using base = complex<double>;
using vec = vector<base>;

ll N, K;
vector<ll> A, B;

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

vector<ll> Multiply(vector<ll> &aa, vector<ll> &bb)
{
    vec a(aa.begin(), aa.end()), b(bb.begin(), bb.end());
    int n = (int)max(a.size(), b.size());
    int i = 0;
    while ((1 << i) < (n << 1)) i++;
    n = 1 << i;
    a.resize(n);
    b.resize(n);
    fft(a ,false);
    fft(b, false);
    for (int i = 0; i < n; i++)
    {
        a[i] *= b[i];
    }
    fft(a, true);

    vector<ll> ret(n);
    for(int i = 0; i < n; i++)
        if(round(a[i].real()) != 0) ret[i] = 1;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    B.resize(1024);
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        B[a] = 1;
    }

    A.push_back(1);
    while (K) {
        if (K % 2 == 1) A = Multiply(A, B);
        B = Multiply(B, B);
        K /= 2;
    }

    for (int i = 0; i < A.size(); i++) {
        if (A[i] != 0) cout << i << " ";
    }
    cout << "\n";
    return 0;
}