#include <iostream>
#define MAX 100000

using namespace std;
using ll = long long;

int N;
ll tree[MAX * 5], A[MAX];

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

void init(int node, int s, int e) {
    if (s == e) tree[node] = s;
    else {
        int mid = (s + e) / 2;
        init(node * 2, s, mid);
        init(node * 2 + 1, mid + 1, e);
        ll left = A[tree[node * 2]];
        ll right = A[tree[node * 2 + 1]];
        if (left <= right) tree[node] = tree[node * 2];
        else tree[node] = tree[node * 2 + 1];
    }
}

ll query(int node, int s, int e, int qs, int qe) {
    if (e < qs || s > qe) return -1;
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

ll maxSalary(int s, int e) {
    ll gIndex = query(1, 1, N, s, e);
    ll ret = (e - s + 1) * A[gIndex];
    if (s <= gIndex - 1) {
        ll x = maxSalary(s, gIndex - 1);
        ret = max(ret, x);
    } 
    if (gIndex + 1 <= e) {
        ll x = maxSalary(gIndex + 1, e);
        ret = max(ret, x);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    init(1, 1, N);
    ll ret = maxSalary(1, N);
    cout << ret << "\n";
    return 0;
}