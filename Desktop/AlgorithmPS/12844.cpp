#include <iostream>
#define MAX 500005

using namespace std;
using ll = long long;

ll N, M, A[MAX], tree[MAX * 6], lazy[MAX * 6];

ll pxor(ll x, ll n) { return (n % 2 == 1) ? x : 0; }

void init(int node, int s, int e) {
    if (s == e) tree[node] = A[s];
    else {
        int mid = (s + e) / 2;
        init(node * 2, s, mid);
        init(node * 2 + 1, mid + 1, e);
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }
}

void lazyUpdate(int node, int s, int e) {
    if (lazy[node] != 0) {
        tree[node] = tree[node] ^ pxor(lazy[node], (e - s + 1));
        if (s != e) {
            lazy[node * 2] = lazy[node * 2] ^ lazy[node];
            lazy[node * 2 + 1] = lazy[node * 2 + 1] ^ lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int s, int e, int qs, int qe, ll k) {
    lazyUpdate(node, s, e);
    if (s > qe || e < qs) return;
    if (qs <= s && e <= qe) {
        tree[node] = tree[node] ^ pxor(k, (e - s + 1));
        if (s != e) {
            lazy[node * 2] = lazy[node * 2] ^ k;
            lazy[node * 2 + 1] = lazy[node * 2 + 1] ^ k;
        }
    } else {
        int mid = (s + e) / 2;
        update(node * 2, s, mid, qs, qe, k);
        update(node * 2 + 1, mid + 1, e, qs, qe, k);
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }
}   

ll query(int node, int s, int e, int qs, int qe) {
    lazyUpdate(node, s, e);
    if (s > qe || e < qs) return 0;
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, qs, qe) ^ query(node * 2 + 1, mid + 1, e, qs, qe);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    init(1, 1, N);
    cin >> M;
    while (M--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll i,j,k;
            cin >> i >> j >> k;
            update(1, 1, N, i + 1, j + 1, k);
        } else {
            ll i,j;
            cin >> i >> j;
            ll ret = query(1, 1, N, i + 1, j + 1);
            cout << ret << "\n";
        }
    }
    return 0;
}