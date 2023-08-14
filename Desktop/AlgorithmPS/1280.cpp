#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
using ll = long long;
struct Data
{
    ll val;
    int num;

    Data(ll _val = 0, int _num = 0): val(_val), num(_num) {}

    Data operator=(const Data &d) {
        this->val = d.val;
        this->num = d.num;
        return *this;
    }

    Data operator+(const Data &d) {
        return Data(this->val + d.val, this->num + d.num);
    }
} tree[800040];

int N;
ll X[200010];

ll bound(ll x, ll dx) {
    ll nx = x + dx;
    if (nx < 0) return 0;
    if (nx > 200003) return 200003;
    return nx;
}

Data update(int node, int s, int e, int pos) {
    if (pos < s || e < pos) return tree[node];
    if (s == e) return tree[node] = tree[node] + Data(pos, 1);
    int mid = (s + e) / 2;
    return tree[node] = update(node * 2, s, mid, pos) + update(node * 2 + 1, mid + 1, e, pos);
}

Data query(int node, int s, int e, int qs, int qe) {
    if (s > qe || e < qs) return Data(0, 0);
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, qs, qe) + query(node * 2 + 1, mid + 1, e, qs, qe);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
    }
    ll ret = 1;
    update(1, 0, 200003, X[1]);
    for (int i = 2; i <= N; i++) {
        Data l = query(1, 0, 200003, 0, bound(X[i], -1));
        Data r = query(1, 0, 200003, bound(X[i], 1), 200003);
        ll cost = ((X[i] * l.num - l.val) + (r.val - X[i] * r.num)) % MOD;
        ret = (ret * cost) % MOD;
        update(1, 0, 200003, X[i]);
    }
    cout << ret << "\n";
    return 0;
}