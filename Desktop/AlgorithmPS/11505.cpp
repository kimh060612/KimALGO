#include <iostream>
#include <vector>
#define MOD 1000000007
#define MAXN 1000001

using namespace std;
using ll = long long;

ll init(vector<int> &a, vector<ll> &tree, int node, int s, int e) {
    if (s == e) {
        return tree[node] = a[s];
    }
    int mid = (s + e) / 2;
    return tree[node] = (init(a, tree, node * 2, s, mid) * init(a, tree, node * 2 + 1, mid + 1, e)) % MOD;
}

ll update(vector<ll> &tree, int node, int s, int e, int index, int mul) {
    if (index < s || index > e) return tree[node];
    if (s == e) return tree[node] = mul;
    else {
        int mid = (s + e) / 2;
        return tree[node] = (update(tree, node * 2, s, mid, index, mul) * update(tree, node * 2 + 1, mid + 1, e, index, mul)) % MOD;
    } 
}

ll query(vector<ll> &tree, int node, int s, int e, int left, int right) {
    if (left > e || right < s) return 1;
    if (left <= s && e <= right) {
        return tree[node];
    }
    else {
        int mid = (s + e) / 2;
        return (query(tree, node * 2, s, mid, left, right) * query(tree, node * 2 + 1, mid + 1, e, left, right)) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(MAXN);
    vector<ll> tree(MAXN * 4);
    for (int i = 1; i <= n; i++) cin >> A[i];

    init(A, tree, 1, 1, n);
    for (int i = 1; i <= m + k; i++) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            update(tree, 1, 1, n, b, c);
            A[b] = c;
        } else {
            cin >> b >> c;
            ll k = query(tree, 1, 1, n, b, c);
            cout << k << "\n";
        }
    }

    return 0;
}