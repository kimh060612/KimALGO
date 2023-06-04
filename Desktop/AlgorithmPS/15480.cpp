#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;
using iip = pair<int, int>;

int N, M, h;
vector<int> T[100001];
int parent[100001][25], depth[100001];

void dfs(int x) {
    for (int nx: T[x]) {
        if (depth[nx] == -1) {
            depth[nx] = depth[x] + 1;
            parent[nx][0] = x;
            dfs(nx);
        }
    }
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void init() {
    memset(depth, -1, sizeof(depth));
    memset(parent, -1, sizeof(parent));
    depth[1] = 0;
    dfs(1);

    for (int j = 0; j < h; j++) 
        for (int i = 2; i <= N; i++)
            if (parent[i][j] != -1)
                parent[i][j + 1] = parent[parent[i][j]][j];
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int j = 0; diff; j++) {
        if (diff % 2) a = parent[a][j];
        diff /= 2;
    }

    if (a != b) {
        for (int j = h - 1; j >= 0; j--) {
            if(parent[a][j] != -1 && parent[a][j] != parent[b][j]){
                a = parent[a][j];
                b = parent[b][j];
            }
        }
        a = parent[a][0];
    }
    return a;
}

int query(iip uv, iip ur, iip vr) {
    iip arr[3] = {uv, ur, vr};
    sort(arr, arr + 3);
    return arr[2].second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    h = (int)ceil(log2(N) + 1);
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    cin >> M;
    init();

    while (M--) {
        int r, u, v;
        cin >> r >> u >> v;
        int uv = LCA(u, v);
        int ur = LCA(u, r);
        int vr = LCA(v, r);
        int ans = query({ depth[uv], uv }, { depth[ur], ur }, { depth[vr], vr });
        cout << ans << "\n";
    }
    return 0;
}