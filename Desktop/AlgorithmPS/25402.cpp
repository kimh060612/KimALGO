#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll N, Q, C[250005];
vector<int> G[250005], T[250005];
int check[250005], parent[250005], A[250005];
int tP[250005], U[250005];

void makeTree(int now) {
    check[now] = 1;
    for (auto nx: G[now]) {
        if (!check[nx]) {
            T[now].push_back(nx);
            tP[nx] = now;
            makeTree(nx);
        }
    }
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin >> Q;
    makeTree(1);

    ll q = 1;
    while (Q --) {
        int K;
        cin >> K;
        for (int i = 1; i <= K; i++) cin >> A[i];
        for (int i = 1; i <= K; i++) {
            C[A[i]] = 1;
            U[A[i]] = q;
            parent[A[i]] = A[i];
        }

        for (int i = 1; i <= K; i++) {
            if (U[A[i]] == q && U[tP[A[i]]] == q) {
                int p = find(A[i]);
                int pp = find(tP[A[i]]);
                
                C[pp] += C[p];
                parent[p] = pp;
            }
        }

        ll ret = 0;
        for (int i = 1; i <= K; i++) { 
            if (parent[A[i]] == A[i]) {
                ret += C[A[i]] * (C[A[i]] - 1) / 2;
            }
        }
        cout << ret << "\n";
        q++;
    }
    return 0;
}