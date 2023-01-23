#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int N, M;
ll A[100001];
vector<ll> T;

ll min(ll a, ll b) { return a < b ? a : b; }
ll init(int node, int s, int e) {
    if (s == e) return T[node] = A[s];
    int mid = (s + e) / 2;
    return T[node] = min(
        init(node * 2, s, mid), 
        init(node * 2 + 1, mid + 1, e)
    );
}

ll update(int node, int s, int e, int index, ll v) {
    if (index < s || index > e) return T[node];
    if (s == e) {
        A[index] = v;
        return T[node] = v;
    }
    int mid = (s + e) / 2;
    return T[node] = min(
        update(node * 2, s, mid, index, v), 
        update(node * 2 + 1, mid + 1, e, index, v)
    );
}

ll query(int node, int s, int e, int l, int r) {
    if (r < s || l > e) return 1e18;
    if (l <= s && e <= r) return T[node];
    int mid = (s + e) / 2;
    return min(
        query(node * 2, s, mid, l, r),
        query(node * 2 + 1, mid + 1, e, l ,r)
    );
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int h = (int)ceil(log2(N + 1));
    int n = (1 << (h + 1)) + 1;
    T.resize(n, 0);
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    init(1, 1, N);
    cin >> M;
    while (M--) {
        int c;
        cin >> c;
        if (c == 1) {
            ll i, v;
            cin >> i >> v;
            update(1, 1, N, i, v);
        } else {
            int i, j;
            cin >> i >> j;
            ll ans = query(1, 1, N, i, j);
            cout << ans << "\n";
        }
    }
    return 0;
}