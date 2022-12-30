#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using vll = vector<ll>;

ll n, s;
ll p[44];
vll a, b;
 
void go(int i, int last, ll sum, vll &x) {
    if (i == last) {
        x.push_back(sum);
        return;
    }
    go(i + 1, last, sum + p[i], x);
    go(i + 1, last, sum, x);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    go(0, n / 2 + 1, 0, a);
    go(n / 2 + 1, n, 0, b);
 
    sort(b.begin(), b.end());
 
    ll ans = 0;
    for (ll i: a) {
        auto l = lower_bound(b.begin(), b.end(), s - i);
        auto u = upper_bound(b.begin(), b.end(), s - i);
        ans += u - l;
    }
    if (s == 0) ans--;
    cout << ans;
}