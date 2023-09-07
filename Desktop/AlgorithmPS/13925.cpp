#include <iostream>
#include <string.h>
#define MAX 100005
#define MOD 1000000007

using namespace std;
using ll = long long;

ll N, M, A[MAX], tree[MAX * 5], lazySum[MAX * 5], lazyMul[MAX * 5];

void init(int node, int s, int e) {
    if (s == e) tree[node] = A[s];
    else {
        int mid = (s + e) / 2;
        init(node * 2, s, mid);
        init(node * 2 + 1, mid + 1, e);
        tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
    }
}

void updateLazy(int node, int s, int e) {
    if (lazyMul[node] == 1 && lazySum[node] == 0) return;
    else {
        tree[node] = (lazyMul[node] * tree[node] + (e - s + 1) * lazySum[node]) % MOD; 
        if (s != e) {
            lazyMul[node * 2] = (lazyMul[node] * lazyMul[node * 2]) % MOD;
            lazySum[node * 2] = (lazyMul[node] * lazySum[node * 2] + lazySum[node]) % MOD;
            lazyMul[node * 2 + 1] = (lazyMul[node] * lazyMul[node * 2 + 1]) % MOD;
            lazySum[node * 2 + 1] = (lazyMul[node] * lazySum[node * 2 + 1] + lazySum[node]) % MOD;
        }
        lazyMul[node] = 1;
        lazySum[node] = 0;
    }
}

void update(int node, int s, int e, int qs, int qe, ll sum, ll mul) {
    updateLazy(node, s, e);
    if (s > qe || e < qs) return;
    if (qs <= s && e <= qe) {
        tree[node] = (mul * tree[node] + (e - s + 1) * sum) % MOD; 
        if (s != e) {
            lazyMul[node * 2] = (mul * lazyMul[node * 2]) % MOD;
            lazySum[node * 2] = (mul * lazySum[node * 2] + sum) % MOD;
            lazyMul[node * 2 + 1] = (mul * lazyMul[node * 2 + 1]) % MOD;
            lazySum[node * 2 + 1] = (mul * lazySum[node * 2 + 1] + sum) % MOD;
        }
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, qs, qe, sum, mul);
    update(node * 2 + 1, mid + 1, e, qs, qe, sum, mul);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

ll query(int node, int s, int e, int qs, int qe) {
    updateLazy(node, s, e);
    if (s > qe || e < qs) return 0;
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    return (query(node * 2, s, mid, qs, qe) + query(node * 2 + 1, mid + 1, e, qs, qe)) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> M;
    for (int i = 1; i <= 4 * MAX; i++) lazyMul[i] = 1;

    init(1, 1, N);
    while (M --) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x, y, v;
            cin >> x >> y >> v;
            update(1, 1, N, x, y, v, 1);
        } else if (t == 2) {
            ll x, y, v;
            cin >> x >> y >> v;
            update(1, 1, N, x, y, 0, v);
        } else if (t == 3) {
            ll x, y, v;
            cin >> x >> y >> v;
            update(1, 1, N, x, y, v, 0);
        } else {
            ll x, y;
            cin >> x >> y;
            ll ret = query(1, 1, N, x, y);
            cout << ret << "\n";
        }
    }
    return 0;
}