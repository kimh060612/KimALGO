#include <iostream>
#include <vector>
#include <string.h>
#define MAX 100005

using namespace std;
using ll = long long;

ll N, M, A[MAX * 3];
ll tree[MAX * 8];

void init(int node, int s, int e) {
    if (s == e) {
        if (s <= M) tree[node] = 0;
        else tree[node] = 1;
    }
    else {
        int mid = (s + e) / 2;
        init(node * 2, s, mid);
        init(node * 2 + 1, mid + 1, e);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(int node, int s, int e, int qs, int qe, ll k) {
    if (qs > e || s > qe) return;
    tree[node] += k;
    if (s != e) {
        int mid = (s + e) / 2;
        update(node * 2, s, mid, qs, qe, k);
        update(node * 2 + 1, mid + 1, e, qs, qe, k);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

ll query(int node, int s, int e, int qs, int qe) {
    if (qs > e || s > qe) return 0;
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, qs, qe) + query(node * 2 + 1, mid + 1, e, qs, qe);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        memset(tree, 0, sizeof(tree));
        memset(A, 0, sizeof(A));
        for (int i = 1; i <= N; i++) A[i] = i + M;
        init(1, 1, N + M);
        for (int i = 1; i <= M; i++) {
            int a;
            cin >> a;
            ll ret = query(1, 1, N + M, 1, A[a]);
            cout << ret - 1 << " ";
            update(1, 1, N + M, A[a], A[a], -1);
            update(1, 1, N + M, M - i, M - i, 1);
            A[a] = M - i;
        }
        cout << "\n";
    }
    return 0;
}