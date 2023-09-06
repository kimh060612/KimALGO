#include <iostream>
#define MAX 100005

using namespace std;
using ll = long long;

ll N, A[MAX], tree[MAX * 5], lazy[MAX * 5], Q;

void updateLazy(int node, int s, int e) {
    if (lazy[node]) {
        tree[node] += (e - s + 1) * lazy[node];
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int s, int e, int qs, int qe, ll k) {
    updateLazy(node, s, e);
    if (s > qe || e < qs) return;
    if (qs <= s && e <= qe) {
        tree[node] += (e - s + 1) * k;
        if (s != e) {
            lazy[node * 2] += k;
            lazy[node * 2 + 1] += k;
        }
    } else {
        int mid = (s + e) / 2;
        update(node * 2, s, mid, qs, qe, k);
        update(node * 2 + 1, mid + 1, e, qs, qe, k);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

ll query(int node, int s, int e, int qs, int qe) {
    updateLazy(node, s, e);
    if (s > qe || e < qs) return 0;
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    ll left = query(node * 2, s, mid, qs, qe);
    ll right = query(node * 2 + 1, mid + 1, e, qs, qe);
    return left + right;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> Q;

    for (int i = 1; i <= N; i++) update(1, 1, N, i, i, A[i] - A[i - 1]);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll l, r;
            cin >> l >> r;
            update(1, 1, N, l, r, 1);
            update(1, 1, N, r + 1, r + 1, -(r - l + 1));
        } else {
            ll x;
            cin >> x;
            ll ret = query(1, 1, N, 1, x);
            cout << ret << "\n";
        }
    }
    return 0;
}