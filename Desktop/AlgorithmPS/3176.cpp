#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#define INF 987654321

using namespace std;
using iip = pair<int, int>;

int N, K, minT[100001][32], maxT[100001][32], visited[100001];
int parent[100001][32], depth[100001], h;
vector<iip> G[100001];
vector<iip> T[100001];

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void makeTree(int now) {
    visited[now] = 1;
    for (auto elem: G[now]) {
        int nx = elem.first;
        int nw = elem.second;
        if (!visited[nx]) {
            T[now].push_back({ nx, nw });
            parent[nx][0] = now;
            minT[nx][0] = nw;
            maxT[nx][0] = nw;
            depth[nx] = depth[now] + 1;
            makeTree(nx);
        } 
    }
}

iip findLCA(int u, int v) {
    int minu = INF, minv = INF;
    int maxu = -INF, maxv = -INF;
    if (depth[u] != depth[v]) {
        if (depth[u] < depth[v]) swap(u, v);
        int diff = depth[u] - depth[v];
        int k = 0;
        while (diff) {
            if (diff % 2 == 1) {
                minu = min(minu, minT[u][k]);
                maxu = max(maxu, maxT[u][k]);
                u = parent[u][k];
            }
            k++;
            diff /= 2;
        }
    }
    if (u != v) {
        for (int i = h - 1; i >= 0; i--) {
            if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
                minu = min(minu, minT[u][i]);
                maxu = max(maxu, maxT[u][i]);
                minv = min(minv, minT[v][i]);
                maxv = max(maxv, maxT[v][i]);
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        minu = min(minu, minT[u][0]);
        maxu = max(maxu, maxT[u][0]);
        minv = min(minv, minT[v][0]);
        maxv = max(maxv, maxT[v][0]);
        u = parent[u][0];
    }
    return { min(minu, minv), max(maxu, maxv) };
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    h = (int)ceil(log2(N + 1));
    for (int i = 1; i < N; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({ b, w });
        G[b].push_back({ a, w });
    }
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i <= h; i++) {
        for (int j = 1; j <= N; j++) {
            minT[j][i] = INF;
            maxT[j][i] = -INF;   
        }
    }
    makeTree(1);

    for (int i = 0; i < h; i++) {
        for (int j = 2; j <= N; j++) {
            if (parent[j][i] != -1) {
                parent[j][i + 1] = parent[parent[j][i]][i];
                minT[j][i + 1] = min(minT[j][i], minT[parent[j][i]][i]);
                maxT[j][i + 1] = max(maxT[j][i], maxT[parent[j][i]][i]);
            }
        }
    }

    cin >> K;
    while (K--) {
        int u, v;
        cin >> u >> v;
        iip ret = findLCA(u, v);
        cout << ret.first << " " << ret.second << "\n";
    }
    return 0;
}