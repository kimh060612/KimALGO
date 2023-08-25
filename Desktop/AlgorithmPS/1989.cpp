#include <iostream>
#define MAX 100005

using namespace std;
using ll = long long;
using iip = pair<int, int>;
using iiip = pair<ll, pair<int, int>>;

ll N, A[MAX], tree[MAX * 5], stree[MAX * 5];

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

void init(int node, int s, int e) {
    if (s == e) {
        tree[node] = s;
        stree[node] = A[s];
    }
    else {
        int mid = (s + e) / 2;
        init(node * 2, s, mid);
        init(node * 2 + 1, mid + 1, e);
        if (A[tree[node * 2]] <= A[tree[node * 2 + 1]]) tree[node] = tree[node * 2];
        else tree[node] = tree[node * 2 + 1];
        stree[node] = stree[node * 2] + stree[node * 2 + 1];
    }
}

ll query(int node, int s, int e, int qs, int qe) {
    if (s > qe || e < qs) return -1;
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    ll left = query(node * 2, s, mid, qs, qe);
    ll right = query(node * 2 + 1, mid + 1, e, qs, qe);
    if (left == -1) return right;
    else if (right == -1) return left;
    else {
        if (A[left] <= A[right]) return left;
        else return right;
    }
}

ll querySum(int node, int s, int e, int qs, int qe) {
    if (s > qe || e < qs) return 0;
    if (qs <= s && e <= qe) return stree[node];
    int mid = (s + e) / 2;
    return querySum(node * 2, s, mid, qs, qe) + querySum(node * 2 + 1, mid + 1, e, qs, qe);
}

iiip dac(int s, int e) {
    int gIndex = query(1, 1, N, s, e); 
    ll ret = querySum(1, 1, N, s, e) * A[gIndex];
    iip retIndex = { s, e };
    if (s <= gIndex - 1) {
        iiip x = dac(s, gIndex - 1);
        if (ret < x.first) retIndex = x.second;
        ret = max(ret, x.first);
    }
    if (gIndex + 1 <= e) {
        iiip x = dac(gIndex + 1, e);
        if (ret < x.first) retIndex = x.second;
        ret = max(ret, x.first);
    }
    return { ret, retIndex };
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    init(1, 1, N);

    iiip ret = dac(1, N);
    cout << ret.first << "\n";
    cout << ret.second.first << " " << ret.second.second << "\n";
    return 0;
}