#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using iip = pair<int, int>;
using dip = pair<double, int>;

int N, sz = 0, IDX[300005];
iip X[300005], Y[300005];
ll DP[300005], DP2[300005];
double x[300005];

bool compare(const iip &i, const iip &j) {
    if (i.first == j.first) return i.second < j.second;
    return i.first < j.first;
}

ll max(ll a, ll b) {
    return a > b ? a : b;
}

ll outter(iip x1, iip x2) {
    return (ll)x1.first * (ll)x2.first + (ll)x1.second * (ll)x2.second;
}

double cross(int i, int j) {
    return (double) (Y[i].second - Y[j].second) / (double) (Y[j].first - Y[i].first);
}

void insert(iip k, int idx) {
    Y[sz] = k;
    IDX[sz] = idx;
    while (sz > 1 && cross(sz - 2, sz - 1) > cross(sz - 1, sz)) {
        Y[sz - 1] = Y[sz];
        IDX[sz - 1] = IDX[sz];
        sz--;
    }
    sz ++;
}

dip query(double k) {
    int l = 0, r = sz - 1;
    while (l != r) {
        int m = (l + r) / 2;
        if (cross(m, m + 1) <= k) l = m + 1;
        else r = m;
    }
    return { Y[l].second + Y[l].first * k, IDX[l] };
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> X[i].first >> X[i].second;
    sort(X + 1, X + 1 + N, compare);
    for (int i = 1; i <= N; i++) x[i] = X[i].first / (double)X[i].second;
    
    ll res = -9876543210;
    insert(X[1], 1);
    for (int i = 2; i <= N; i++) {
        dip a = query(x[i]);
        insert(X[i], i);
        DP[i] = outter(X[i], X[a.second]);
        res = max(res, DP[i]);
    }

    cout << res << "\n";
    return 0;
}