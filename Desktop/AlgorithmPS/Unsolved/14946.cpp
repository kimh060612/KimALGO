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
int tDP[1001][5][15];

bool canMake(int nowColor, int nxColor) {
    if (nowColor == 1) return true;
    else if (nowColor == 2) return nxColor != 2;
    else return nowColor == 2;
}

void makeTree(int now, int parent) {
    for (int i = 0; i < G[now].size(); i++) {
        int next = G[now][i];
        if (next == parent) continue;
        T[now].push_back(next);
        makeTree(next, now);
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

    cout << ans << "\n";
    return 0;
}