#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
using iip = pair<int, int>;

int V, Q, K;
vector<int> G[1001];
vector<int> T[1001];
int Cost[1001][5];
int tMem[1001][5][15], tDP[1001][5][15];
int tCheck[1001][5];

bool canMake(int nowColor, int nxColor) {
    if (nowColor == 1) return nxColor != 3;
    else if (nowColor == 2) return nxColor != 2;
    else if (nowColor == 3) return nxColor == 2;
    else return false;
}

void makeTree(int now, int parent) {
    for (int i = 0; i < G[now].size(); i++) {
        int next = G[now][i];
        if (next == parent) continue;
        T[now].push_back(next);
        makeTree(next, now);
    }
}

void dupProd(int n_idx, int n_color, int cost, int mul, int parent, int pcolor) {
    if (n_idx + 1 == T[parent].size()) {
        int tmp = (Cost[parent][pcolor] + cost) % K;
        tMem[parent][pcolor][tmp] = (tMem[parent][pcolor][tmp] + mul) % Q;
        return;
    }

    int nx = T[parent][n_idx];
    int nnx = T[parent][n_idx + 1];

    for (int nc = 1; nc <= 3; nc++) {
        if (canMake(pcolor, nc)) {
            for (int k = 0; k < K; k++) {
                if (tMem[nnx][nc][k] != 0) {
                    int ncost = (cost + k) % K;
                    int nmul = (mul * tMem[nnx][nc][k]) % Q;
                    dupProd(n_idx + 1, nc, ncost, nmul, parent, pcolor);
                }
            }
        }
    }
}

void dfs(int now, int ncolor) {
    tCheck[now][ncolor] = 1;
    if (T[now].empty()) {
        int tmp = Cost[now][ncolor] % K;
        tMem[now][ncolor][tmp] = 1;
        return;
    }

    for (int nxcolor = 1; nxcolor <= 3; nxcolor++) {
        if (canMake(ncolor, nxcolor)) {
            for (int i = 0; i < T[now].size(); i++) {
                int nx = T[now][i];
                if(!tCheck[nx][nxcolor]) dfs(nx, nxcolor);
            }
        }
    }

    int nxnode = T[now][0];
    for (int nxcolor = 1; nxcolor <= 3; nxcolor++) {
        if (canMake(ncolor, nxcolor)) { 
            for (int k = 0; k < K; k++) {
                if (tMem[nxnode][nxcolor][k] != 0) {
                    dupProd(0, nxcolor, k, tMem[nxnode][nxcolor][k] % Q, now, ncolor);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> Q >> K;
    for (int i = 1; i < V; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= V; i++) { // R: 1, G: 2, B: 3
        cin >> Cost[i][1] >> Cost[i][2] >> Cost[i][3];
    }
    makeTree(1, 0);

    int ans = 0;
    for (int c = 1; c <= 3; c++)
        dfs(1, c);
    for (int c = 1; c <= 3; c++)
        ans  = (ans + tMem[1][c][0]) % Q;
    // cout << "\n\n";
    // for (int i = 1; i <= V; i++) {
    //     cout << i << ": " << "\n";
    //     for (int c = 1; c <= 3; c++) {
    //         cout << "checked?: " << tCheck[i][c] << " ";
    //         cout << "Color " << c << " : ";
    //         for (int k = 0; k < K; k++) {
    //             cout << tMem[i][c][k] << " ";
    //         }
    //         cout << "\n";
    //     }
    // }
    cout << ans << "\n";
    return 0;
}
