#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int N, Q;
int A[100001];
vector<ll> T;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

ll init(int node, int s, int e) {
    if (s == e) return T[node] = A[s];
    int mid = (s + e) / 2;
    return T[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

ll update(int node, int s, int e, int index, int k) {
    if (s > index || index > e) return T[node];
    if (s == e) {
        A[index] = k;
        return T[node] = k;
    }
    int mid = (s + e) / 2;
    return T[node] = update(node * 2, s, mid, index, k) + update(node * 2 + 1, mid + 1, e, index, k);
}

ll query(int node, int s, int e, int l, int r) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return T[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    int h = (int)ceil(log2(N + 1) + 1);
    int n = (1 << (h + 1)) + 1;
    T.resize(n);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    init(1, 1, N);
    while (Q--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        ll k = query(1, 1, N, x, y);
        cout << k << "\n";
        update(1, 1, N, a, b);
    }
    return 0;
}