#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

ll nCr[1005][1005];

double B(double x, int n, int m) {
    return pow(x, m) * pow(1 - x, n - m);
}

double pB(double x, int n, int m) {
    if (n == m) {
        return m * pow(x, m - 1);
    } else {
        return (m * pow(x, m - 1) * pow(1 - x, n - m)) - (((double)n - m) * pow(x, m) * pow(1 - x, n - m - 1));
    }
}

double totalArea(int n1, int m1, int n2, int m2) {
    double dq = 1e-3;
    double dp = 1e-3;
    double ret1 = 0, ret2 = 0;
    for (double q = 0; q <= 1; q += dq) {
        ret1 += pB(q, n2, m2) * dq;
    }
    for (double p = 0; p <= 1; p += dp) {
        ret2 += pB(p, n1, m1) * dp;
    }
    return ret1 * ret2;
}

double upperArea(int n1, int m1, int n2, int m2) {
    double dq = 1e-3;
    double dp = 1e-3;
    double ret = 0;
    for (double q = 0; q <= 1; q += dq) {
        double tmp = 0;
        for (double p = 0; p < q; p += dp) {
            double y = pB(q, n2, m2) * pB(p, n1, m1);
            tmp += y * dp;
        }
        ret += tmp * dq;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    int t;
    cin >> t;
    for (int i = 1; i <= 1000; i++) {
        nCr[i][0] = 1;
        nCr[i][i] = 1;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j < i; j++) nCr[i][j] = nCr[i - 1][j - 1] + nCr[i - 1][j];
    }
    cout << fixed;
    while (t--) {
        int n1, m1, n2, m2;
        cin >> n1 >> m1 >> n2 >> m2;
        double f = (double)nCr[n1][m1] / (double)nCr[n2][m2];
        double alpha = B((double)m2 / (double)n2, n2, m2);
        double beta = B((double)m1 / (double)n1, n1, m1);
        double coeff = 0.5 * f * beta * beta;
        // double PX_A = upperArea(n1, m1, n2, m2) * coeff;
        // double PX = totalArea(n1, m1, n2, m2) * coeff;
        // cout << coeff << " " << PX_A << " " << PX << "\n";
        // double ret = ((PX_A * 0.5) / PX);
        // cout << ret << "\n";
        double temp = 1;
        for(int i = 0; i <= m1; i++)
            temp = temp * (n1 + 1 - i) / (double)(n1 + n2 + 2 - i);
        double ret = temp;
        for(int i = 1; i <= m2; i++) {
            temp = temp * ((m1 + i) / (double)i) * ((n2 + 2 - i)/(double)(n1 + n2 - m1 + 2 - i));
            ret += temp;
        }
        cout << ret << "\n";
    }
    return 0;
}