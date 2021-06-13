#include <iostream>
#include <string>
#include <complex>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

string S, T;

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
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        res[i] = (int)round(a[i].real());
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> T;
    if (S.compare("0") == 0|| T.compare("0") == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<base> A, B;
    for (int i = 0; i < S.size(); i++)
    {
        A.push_back({(double)(S[i] - '0'), 0});
    }
    for (int i = 0; i < T.size(); i++)
    {
        B.push_back({(double)(T[i] - '0'), 0});
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    vector<int> C;
    C = multiply(A, B);
    for (int i = 0; i < C.size(); i++)
    {
        if (C[i] >= 10)
        {
            if (i == C.size() - 1) C.push_back(C[i] / 10);
            else C[i + 1] += C[i] / 10;
            C[i] = C[i] % 10;
        }
    }
    
    while (1) 
    {
        if (C[C.size() - 1] != 0)break;
        else {
            C.pop_back();
        }
    }

    reverse(C.begin(), C.end());
    for (int i = 0; i < C.size(); i++)
    {
        cout << C[i];
    }
    cout << endl;
    return 0;
}