#include <iostream>
#include <string.h>

using namespace std;

int N, M;
int Adj[1001][1001], pMatch[1001], wMatch[1001];
int visited[1001];

bool dfs(int x) {
    if (visited[x]) return false;
    visited[x] = 1;
    for (int i = 1; i <= M; i++) {
        if (Adj[x][i]) {
            if (!wMatch[i] || dfs(wMatch[i])) {
                wMatch[i] = x;
                pMatch[x] = i;
                return true;
            }
        }
    }
    return false;
}

int bipartiteMatching() {
    memset(pMatch, 0, sizeof(pMatch));
    memset(wMatch, 0, sizeof(wMatch));

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

    int res = bipartiteMatching();
    cout << res << "\n";
    return 0;
}