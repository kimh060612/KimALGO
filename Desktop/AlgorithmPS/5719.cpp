#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
using iip = pair<int, int>;
int N, M, S, D;
int Map[501][501], isShortestPath[501][501];
int dist[501];
vector<int> check[501];
int mark[501];

void bfs() {
    queue<int> Q;
    Q.push(D);

    memset(mark, 0, sizeof(mark));
    while (!Q.empty()) 
    {
        int x = Q.front();
        Q.pop();

        for (int i = 0; i < check[x].size(); i++) {
            int nx = check[x][i];
            isShortestPath[nx][x] = 1;
            if (mark[nx]) continue;
            Q.push(nx);
            mark[nx] = 1;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        cin >> S >> D;
        for (int i = 0; i < N; i++)
            check[i].clear(); 
        for (int i = 0; i < N; i++)
            dist[i] = 987654321;
        dist[S] = 0;
        memset(isShortestPath, 0, sizeof(isShortestPath));
        memset(Map, 0, sizeof(Map));
        check[S].push_back(S);
        for (int i = 1; i <= M; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            Map[u][v] = p;
        }

        priority_queue<iip> Q;
        Q.push({ 0, S });

        while (!Q.empty()) {
            int now_dist = -1 * Q.top().first;
            int now_pos = Q.top().second;
            Q.pop();

            for (int i = 0; i < N; i++) {
                if (Map[now_pos][i] != 0) {
                    int nx_pos = i;
                    int nx_dist = now_dist + Map[now_pos][i];
                    if (nx_dist < dist[nx_pos]) {
                        dist[nx_pos] = nx_dist;
                        Q.push({ -1 * nx_dist, nx_pos });
                        if (check[nx_pos].size() != 0)
                            check[nx_pos].clear();
                        check[nx_pos].push_back(now_pos);
                    } else if (nx_dist == dist[nx_pos]) {
                        check[nx_pos].push_back(now_pos);
                    }
                }
            }
        }
        bfs();

        for (int i = 0; i < N; i++) {
            cout << i << "------------" << endl;
            for (int j = 0; j < check[i].size(); j++) 
            {
                cout << check[i][j] << " ";
            }
            cout << endl;
            cout << "-----------------" << endl;
        }

        for (int i = 0; i < N; i++)
            dist[i] = 987654321;
        dist[S] = 0;

        priority_queue<iip> pq;
        pq.push({ 0, S });

        while (!pq.empty()) {
            int now_dist = -1 * pq.top().first;
            int now_pos = pq.top().second;
            pq.pop();

            for (int i = 0; i < N; i++) {
                if (Map[now_pos][i] != 0) {
                    int nx_pos = i;
                    int nx_dist = now_dist + Map[now_pos][i];
                    if (nx_dist < dist[nx_pos] && !isShortestPath[now_pos][nx_pos]) {
                        dist[nx_pos] = nx_dist;
                        pq.push({ -1 * nx_dist, nx_pos });
                    }
                }
            }
        }

        if (dist[D] == 987654321) cout << -1 << "\n";
        else cout << dist[D] << "\n";
    }    
    return 0;
}