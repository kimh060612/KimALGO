#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

ll A[100001];
vector<ll> Te, To;
int N, M;

ll initEven(int node, int s, int e) {
    if (s == e) return Te[node] = (A[s] % 2 == 0);
    int mid = (s + e) / 2;
    return Te[node] = initEven(node * 2, s, mid) + initEven(node * 2 + 1, mid + 1, e);
}

ll initOdd(int node, int s, int e) {
    if (s == e) return To[node] = (A[s] % 2 == 1);
    int mid = (s + e) / 2;
    return To[node] = initOdd(node * 2, s, mid) + initOdd(node * 2 + 1, mid + 1, e);
}

ll updateEven(int node, int s, int e, int index, ll v) {
    if (s > index || index > e) return Te[node];
    if (s == e) return Te[node] = (v % 2 == 0);
    int mid = (s + e) / 2;
    return Te[node] = updateEven(node * 2, s, mid, index, v) + updateEven(node * 2 + 1, mid + 1, e, index, v);
}

ll updateOdd(int node, int s, int e, int index, ll v) {
    if (s > index || index > e) return To[node];
    if (s == e) return To[node] = (v % 2 == 1);
    int mid = (s + e) / 2;
    return To[node] = updateOdd(node * 2, s, mid, index, v) + updateOdd(node * 2 + 1, mid + 1, e, index, v);
}

ll queryEven(int node, int s, int e, int l, int r) {
    if (e < l || s > r) return 0;
    if (l <= s && e <= r) return Te[node];
    int mid = (s + e) / 2;
    return queryEven(node * 2, s, mid, l, r) + queryEven(node * 2 + 1, mid + 1, e, l, r);
}

ll queryOdd(int node, int s, int e, int l, int r) {
    if (e < l || s > r) return 0;
    if (l <= s && e <= r) return To[node];
    int mid = (s + e) / 2;
    return queryOdd(node * 2, s, mid, l, r) + queryOdd(node * 2 + 1, mid + 1, e, l, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    int h = (int)ceil(log2(N + 1) + 1);
    int n = (1 << (h + 1)) + 1;
    Te.resize(n, 0);
    To.resize(n, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    initEven(1, 1, N);
    initOdd(1, 1, N);
    cin >> M;
    while (M --) {
        int c;
        cin >> c;
        if (c == 1) {
            ll i, v;
            cin >> i >> v;
            updateEven(1, 1, N, i, v);
            updateOdd(1, 1, N, i, v);
        } else if (c == 2) {
            int l, r;
            cin >> l >> r;
            ll ans = queryEven(1, 1, N, l ,r);
            cout << ans << "\n";
        } else {
            int l, r;
            cin >> l >> r;
            ll ans = queryOdd(1, 1, N, l ,r);
            cout << ans << "\n";
        }
    }
    return 0;
}