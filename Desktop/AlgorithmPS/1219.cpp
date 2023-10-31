#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define INF 1e18 + 5

using namespace std;
using ll = long long;
using iip = pair<ll, ll>;
using iiip = pair<iip, ll>;

ll N, M, S, E, P[100], R[100];
int check[100], canEnd[100];
vector<iip> G[100];
vector<iiip> Edge;

void canGo(int s) {
    queue<int> Q;
    Q.push(s);
    memset(check, 0, sizeof(check));
    check[s] = 1;
    
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        if (x == E) {
            canEnd[s] = 1;
            break;
        }
        for (auto node: G[x]) {
            int nx = node.first;
            if (!check[nx]) {
                Q.push(nx);
                check[nx] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> S >> E >> M;
    S += 1; E += 1;
    for (int i = 1; i <= M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a + 1].push_back( { b + 1, w });
        Edge.push_back({ { a + 1, b + 1 }, w });
    }
    for (int i = 1; i <= N; i++) cin >> P[i];
    for (int i = 1; i <= N; i++) R[i] = INF;
    R[S] = -P[S]; canEnd[E] = 1;

    for (int v = 1; v <= N - 1; v++) {
        for (auto node: Edge) {
            int s = node.first.first;
            int e = node.first.second;
            int w = node.second;
            if (R[s] == INF) continue;
            if (R[e] > R[s] + w - P[e]) R[e] = R[s] + w - P[e];
        }
    }
    for (int v = 1; v <= N; v++) {
        if (v == E) continue;
        canGo(v);
    }

    for (auto node: Edge) {
        int s = node.first.first;
        int e = node.first.second;
        int w = node.second;
        if (R[s] == INF) continue;
        if (R[e] > R[s] + w - P[e] || (s == e && P[s] > w)) {
            if (canEnd[e]) {
                cout << "Gee\n";
                return 0;
            }
        }
    }

    if (R[E] == INF) cout << "gg\n";
    else cout << -R[E] << "\n";
    return 0;
}