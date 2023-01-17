#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int N, M;
vector<ll> T, A;

ll init(int node, int s, int e) {
    if (s == e) {
        return T[node] = A[s];
    }
    int mid = (s + e) / 2;
    return T[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e); 
}

ll update(int node, int s, int e, int index, ll k) {
    if (s > index || e < index) return T[node];
    if (s == e) {
        A[index] = k;
        return T[node] = k;
    }
    int mid = (s + e) / 2;
    return T[node] = update(node * 2, s, mid, index, k) + update(node * 2 + 1, mid + 1, e, index, k);
}

ll query(int node, int s, int e, int l, int r) {
    if (s > r || e < l) return 0;
    if (l <= s && e <= r) return T[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    A.resize(N + 1);
    int h = (int)ceil(log2(N + 1));
    int n = (1 << (h + 1)) + 1;
    T.resize(n);
    init(1, 1, N);
    for (int i = 1; i <= M; i++) {
        ll a, b, c;
        cin >> a;
        if (a == 0) {
            cin >> b >> c;  
            if (b > c) swap(b, c);
            ll ans = query(1, 1, N, b, c);
            cout << ans << "\n";
        } else {    
            cin >> b >> c;
            update(1, 1, N, b, c);
        }
    }
    return 0;
}