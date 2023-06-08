#include <iostream>
#include <iomanip>
#include <math.h>
#include <set>
#define EPS 1e-4
#define MAX 2000000

using namespace std;
using ll = long long;
using ld = long double;
using sd = set<ld>;

ll equationll(ll a, ll b, ll c, ll d, ll x) {
    return a * x * x * x + b * x * x + c * x + d;
}

ll onellSolution(ll a, ll b, ll c, ll d) {
    for (ll x = 0; x <= MAX; x++) {
        if (equationll(a, b, c, d, x) == 0) return x;
        if (equationll(a, b, c, d, -x) == 0) return -x;
    }
    return 0;
}

sd findSolution(ll a, ll b, ll c, ll d) {
    sd ans;
    ll x = onellSolution(a, b, c, d);
    ans.insert(x);
    if (b * b > 3 * a * c) { // 함수 꼴이 변곡형.
        ll p = b + a * x;
        ll q = c + x * p;
        if (p * p > 4 * a * q) {
            ld s1 = (-p + (ld)sqrt(p * p - 4 * a * q)) / (ld)(2. * a);
            ld s2 = (-p - (ld)sqrt(p * p - 4 * a * q)) / (ld)(2. * a);
            ans.insert(s1);
            ans.insert(s2);
        } else if (p * p == 4 * a * q) {
            ld s = (ld)(-p) / (ld)(2. * a);
            ans.insert(s);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(12);
    cout << fixed;

    int t;
    cin >> t;
    while (t--) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        sd ans = findSolution(A, B, C, D);
        for (sd::iterator it = ans.begin(); it != ans.end(); it++) {
            cout << (*it) << " ";
        }
        cout << "\n";
    }
    return 0;
}