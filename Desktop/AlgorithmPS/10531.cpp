#include <iostream>
#include <cmath>
#include <complex>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int D[200001], K[200001], bit[200001];

typedef complex<double> base;
 
void fft(vector<base> &a, bool inv) {
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

vector<int> multiply(vector<base> &a, vector<base> &b) {
    int n = (int) max(a.size(), b.size());
    int i = 0;
    while ((1 << i) < (n << 1)) i++;
    n = 1 << i;
    a.resize(n);
    b.resize(n);
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; i++) {
        a[i] *= b[i];
    }
    fft(a, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = (int)round(a[i].real());
    }
    return result;
}

int main()
{
    vector<base> Ka, Da;
    int max_ = -1;
    cin >> N;
    for (int i = 1; i <= N; i++) 
    {
        cin >> K[i];
        max_ = max(max_, K[i]);
        bit[K[i]] = 1;
    }

    Ka.resize(max_ + 1);
    Da.resize(max_ + 1);
    for (int i = 1; i <= N; i++)
    {
        Ka[K[i]] = base(1, 0);
        Da[K[i]] = base(1, 0);
    }

    cin >> M;
    for (int i = 1; i <= M; i++) cin >> D[i];

    vector<int> A;
    A = multiply(Ka, Da);
    A[0] = 1;

    int ans = 0;
    for (int i = 1; i <= M; i++)
    {
        if ((D[i] < A.size() && A[D[i]] != 0) || bit[D[i]]) ans ++;
    }

    cout << ans << endl;

    return 0;
}