#include <iostream>

using namespace std;
using ll = long long;

ll N, X[100001];

ll ABS(ll x) { return x > 0 ? x : -x; }

ll diffSearch(ll d) {
    ll ret = 0, ret2 = 0;
    for (ll i = 1; i < N; i++) {
        ret += ABS(X[i] - d * i);
        ret2 += ABS(X[i] - (d + 1) * i);
    }
    return ret < ret2 ? ret : -1;
}

ll solve() {
    ll s = 1, e = X[N - 1];
    ll mid, ret = 0;
    while (s < e) {
        mid = (s + e) / 2;
        ll fm = diffSearch(mid);
        if (fm == -1) {
            s = mid + 1;
        } else {
            e = mid;
            ret = fm;
        }
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    cout << solve() << "\n";
    return 0;
}