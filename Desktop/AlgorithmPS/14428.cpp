#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;
using lp = pair<ll, int>; 

lp min(lp a, lp b) {
    if (a.first == b.first) return a.second < b.second ? a : b;
    else return a.first < b.first ? a : b; 
}
ll min(ll a, ll b) { return a < b ? a : b; }

lp init(vector<ll> &a, vector<lp> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = {a[start], start};
    } else {
        return tree[node] = min(
            init(a, tree, node*2, start, (start+end)/2),
            init(a, tree, node*2+1, (start+end)/2+1, end)
        );
    }
}

lp update(vector<lp> &tree, int node, int start, int end, int index, ll v) {
    if (index < start || index > end) return tree[node];
    if (start == end) return tree[node] = {v, index};
    return tree[node] = min(
        update(tree,node*2, start, (start+end)/2, index, v), 
        update(tree,node*2+1, (start+end)/2+1, end, index, v)
    );
}

// node가 담당하는 구간이 start~end이고, 구해야하는 합의 범위는 left~right
lp result(vector<lp> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return {1e9 + 1, 100000 + 1};
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return min(
        result(tree, node*2, start, (start+end)/2, left, right), 
        result(tree, node*2+1, (start+end)/2+1, end, left, right)
    );
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> A(n + 1);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    vector<lp> tree(tree_size);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    init(A, tree, 1, 0, n - 1);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int c;
        cin >> c;
        if (c == 1) {
            int x; 
            ll v;
            cin >> x >> v;
            A[x - 1] = v;
            update(tree, 1, 0, n - 1, x - 1, v);
        } else {
            int x, y;
            cin >> x >> y;
            lp k = result(tree, 1, 0, n - 1, x - 1, y - 1);
            cout << k.second + 1 << "\n";
        }
    }

    return 0;
}