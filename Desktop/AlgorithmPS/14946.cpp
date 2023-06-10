#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <tuple>

using namespace std;
using it = tuple<int, int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int V, Q, K;
vector<int> G[1001];
vector<int> T[1001];
vector<int> Leaf;
int Cost[1001][5];
int tMem[1001][5][15], tDP[5][1001][5][15], tVisited[5][1001][5];
int tCheck[1001][5];

bool canMake(int nowColor, int nxColor) {
    if (nowColor == 1) return nxColor != 3;
    else if (nowColor == 2) return nxColor != 2;
    else if (nowColor == 3) return nxColor == 2;
    else return false;
}

bool isVisited(int pcolor, int r, int g, int b) {
    if (pcolor == 1) {
        return (r == 1 && g == 1);
    } else if (pcolor == 2) {
        return (r == 1 && b == 1);
    } else {
        return (g == 1);
    }
}

void makeTree(int now, int parent) {
    for (int i = 0; i < G[now].size(); i++) {
        int next = G[now][i];
        if (next == parent) continue;
        T[now].push_back(next);
        makeTree(next, now);
    }
}

void dfsTree(int depth, int ncolor, int parent, int pcolor) { // 목표: tMem[parent][pcolor]를 적절히 업뎃한다
    int nx = T[parent][depth];
    if (depth + 1 == T[parent].size()) {
        for (int k = 0; k < K; k++) {
            int index = (Cost[parent][pcolor] + k) % K;
            tDP[pcolor][nx][ncolor][index] = tMem[nx][ncolor][k];
        }
        return;
    }

    int nnx = T[parent][depth + 1];
    tVisited[pcolor][nx][ncolor] = 1;
    for (int c = 1; c <= 3; c++) {
        if (canMake(pcolor, c)) {
            if (tVisited[pcolor][nnx][c]) {
                for (int k = 0; k < K; k++) {
                    for (int l = 0; l < K; l++) {
                        int t1 = tMem[nx][ncolor][k];
                        int t2 = tDP[pcolor][nnx][c][l];
                        int &ret = tDP[pcolor][nx][ncolor][(k + l) % K];
                        if (t1 * t2 != 0) ret = (ret + (t1 * t2) % Q) % Q; // !
                    }
                }
            } else {
                dfsTree(depth + 1, c, parent, pcolor);
                // 현재 내가 가지고 있는 tMem과 비교해서 tDP 업뎃
                for (int k = 0; k < K; k++) {
                    for (int l = 0; l < K; l++) {
                        int t1 = tMem[nx][ncolor][k];
                        int t2 = tDP[pcolor][nnx][c][l];
                        int &ret = tDP[pcolor][nx][ncolor][(k + l) % K];
                        if (t1 * t2 != 0) ret = (ret + (t1 * t2) % Q) % Q; // !
                    }
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
            dfsTree(0, nxcolor, now, ncolor);
            for (int k = 0; k < K; k++) { // tMem update!
                tMem[now][ncolor][k] = (tMem[now][ncolor][k] + tDP[ncolor][nxnode][nxcolor][k]) % Q; // !
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
    for (int i = 1; i <= V; i++) {
        if (T[i].empty())
            Leaf.push_back(i);
    }

    int ans = 0;
    for (int c = 1; c <= 3; c++)
        dfs(1, c);
    for (int c = 1; c <= 3; c++)
        ans  = (ans + tMem[1][c][0]) % Q;
    cout << ans << "\n";
    return 0;
}
