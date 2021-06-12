#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int X[200001], Y[200001];

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

vector<long long> Multiply(vector<base> &a, vector<base> &b)
{
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

    vector<long long> result(n);
    for (int i = 0; i < n; i++)
    {
        result[i] = (int)round(a[i].real());
    }
    return result;
}

int main()
{
    cin >> N;
    vector<base> x(2 * N, 0), y(N, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> X[i];
        x[i - 1] = base((double)X[i], 0);
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> Y[i];
        y[i - 1] = base((double)Y[i], 0);
    }
    reverse(y.begin(), y.end());
    for (int i = N; i < 2 * N; i++)
    {
        x[i] = x[i % N];
    }
    vector<long long> c;
    c = Multiply(x, y);
    long long ans = 0;
    for (int i = 0; i < c.size(); i++)
    {
        ans = max(ans, c[i]);
    }
    cout << ans << endl;
    return 0;
}