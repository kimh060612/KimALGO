#include <iostream>
#include <string.h>

using namespace std;

int N, M;
int Adj[201][201], cMatch[201], pMatch[201];
int visited[201];

bool dfs(int x) {
    if (visited[x]) return false;
    visited[x] = 1;
    for (int i = 1; i <= M; i++) {
        if (Adj[x][i]) {
            if (!pMatch[i] || dfs(pMatch[i])) {
                pMatch[i] = x;
                cMatch[x] = i;
                return true;
            }
        }
    }
    return false;
}

int bipartiteMatching() {
    memset(cMatch, 0, sizeof(cMatch));
    memset(pMatch, 0, sizeof(pMatch));

    int size = 0;
    for (int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) size ++;
    }
    return size;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; j++) {
            int a;
            cin >> a;
            Adj[i][a] = 1;
        }
    }

    int ret = bipartiteMatching();
    cout << ret << "\n";

    return 0;
}