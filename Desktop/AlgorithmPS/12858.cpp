#include <iostream>
#define MAX 100000

using namespace std;
using ll = long long;

ll N, Q, A[MAX + 5];
ll tree[MAX * 4], lazy[MAX * 4];
ll treeGCD[MAX * 4];

ll Abs(ll x) { return x < 0 ? -x : x; }
ll gcd(ll a, ll b) { return a == 0 ? b : (b ? gcd(b, a % b) : a); }
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }
void init(int node, int s, int e) {
    if (s == e) {
        tree[node] = A[s];
    } else {
        int mid = (s + e) / 2;
        init(node * 2, s, mid);
        init(node * 2 + 1, mid + 1, e);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void updateLazy(int node, int s, int e) {
    if (lazy[node] != 0) {
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
    return query(node * 2, s, mid, qs, qe) + query(node * 2 + 1, mid + 1, e, qs, qe);
}

ll updateGCD(int node, int s, int e, int x, ll k) {
    if (x < s || x > e) return treeGCD[node];
	if (x == s && x == e) return treeGCD[node] += k;
    int mid = (s + e) / 2;
    return treeGCD[node] = gcd(updateGCD(node * 2, s, mid, x, k), updateGCD(node * 2 + 1, mid + 1, e, x, k));
}

ll queryGCD(int node, int s, int e, int qs, int qe) {
    if (qs > qe) return 0;
    if (qs == s && qe == e) return treeGCD[node];
    int mid = (s + e) / 2;
    return gcd(queryGCD(node * 2, s, mid, qs, min(qe, mid)), queryGCD(node * 2 + 1, mid + 1, e, max(mid + 1, qs), qe));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    init(1, 1, N);
    for (int i = 2; i <= N; i++) {
        updateGCD(1, 1, N, i, A[i] - A[i - 1]);
    }

    while (Q--) {
        ll t, a, b;
        cin >> t >> a >> b;
        if (t == 0) {
            ll now = queryGCD(1, 1, N, a + 1, b);
            ll ret = query(1, 1, N, a, a);
            if (a == b) cout << Abs(ret) << "\n";
            else cout << Abs(gcd(now, ret)) << "\n";
        } else {
            update(1, 1, N, a, b, t);
            updateGCD(1, 1, N, a, t);
			updateGCD(1, 1, N, b + 1, -t);
        }
    }
    return 0;
}