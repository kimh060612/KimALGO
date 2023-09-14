#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
using ll = long long;
using iip = pair<int, ll>;

int N, E[100005], check[100005];
ll dist[100005], parent[100005][30], pDist[100005][30], depth[100005];
vector<iip> G[100005], T[100005];

void makeTree(int now) {
    check[now] = 1;
    for (auto node: G[now]) {
        int nx = node.first;
        ll nw = node.second;
        if (!check[nx]) {
            T[now].push_back({ nx, nw });
            parent[nx][0] = now;
            pDist[nx][0] = nw;
            depth[nx] = depth[now] + 1;
            makeTree(nx);
        }
    }
}

void makeDistance(int x, ll cost) {
    check[x] = 1;
    dist[x] = cost;
    for (auto node: T[x]) {
        int nx = node.first;
        ll nw = node.second;
        if (!check[nx]) makeDistance(nx, cost + nw);
    }
}

iip findUp(int now, int cost) {
    for (int i = 20; i >= 0; i--) {
        if (pDist[now][i] != -1 && parent[now][i] != 0) {
            if (cost >= pDist[now][i]) return { parent[now][i], cost - pDist[now][i] };
        }
    }
    return { now, cost };
}

int findIndex(int now, int cost) {
    while (1) {
        iip tmp = findUp(now, cost);
        if (tmp.first == 1 || now == tmp.first) return tmp.first;
        now = tmp.first;
        cost = tmp.second;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> E[i];
    for (int i = 1; i < N; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({ b, w });
        G[b].push_back({ a, w });
    }
    memset(pDist, -1, sizeof(pDist));
    makeTree(1);
    memset(check, 0, sizeof(check));
    makeDistance(1, 0);

    for (int p = 0; p <= 20; p++) {
        for (int i = 1; i <= N; i++) {
            if (parent[i][p]) {
                parent[i][p + 1] = parent[parent[i][p]][p];
                pDist[i][p + 1] = pDist[parent[i][p]][p] + pDist[i][p];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int ret = findIndex(i, E[i]);
        cout << ret << "\n";
    }
    return 0;
}