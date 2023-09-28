#include <iostream>
#define MAX 10000000

using namespace std;
using ll = long long;

ll a, b, c, d;
int mu[MAX + 5];

void init() {
    mu[1] = 1;
    for (int i = 1; i <= MAX; i++) {
        for (int j = 2 * i; j <= MAX; j += i ) {
            mu[j] -= mu[i];
        }
    }
}

ll min(ll x, ll y) { return x < y ? x : y; }
ll count(ll x, ll y) {
    ll N = min(x, y), ret = 0;
    for (int k = 1; k <= N; k++) {
        ret += (mu[k] * (x / k) * (y / k));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> a >> b >> c >> d;
    ll ret = count(b, d) - count(b, c - 1) - count(a - 1, d) + count(a - 1, c - 1);
    cout << ret << "\n";
    return 0;
}