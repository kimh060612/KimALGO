#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;
using iip = pair<int, int>;

vector<iip> T[1001];
int DP[1001], dist[1001], check[1001];
int N, M;

void minDistance() {
    priority_queue<iip> pq;
    pq.push({ 0, 2 });

    dist[2] = 0;
    while (!pq.empty()) {
        int nowDist = -1 * pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        for (auto nx : T[now]) {
            int nxNode = nx.first;
            if (dist[nxNode] > nx.second + nowDist) {
                pq.push({ -1 * (nx.second + nowDist), nxNode });
                dist[nxNode] = nx.second + nowDist;
            }
        }
    }
}

int dfs(int now) {
    if (now == 2) return 1;
    int &ret = DP[now];
    if (ret != -1) return ret;

    ret = 0;
    for (auto nx: T[now]) {
        int next = nx.first;
        if (dist[now] > dist[next] && !check[next]) { // 합리적인 이동 경로
            check[next] = 1;
            ret += dfs(next);
            check[next] = 0;
        } 
    }   
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dist[i] = 987654321;
    memset(DP, -1, sizeof(DP));
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        T[a].push_back({ b, c });
        T[b].push_back({ a, c });
    }
    minDistance();
    check[1] = 1;
    int ans = dfs(1);

    cout << ans << endl;

    return 0;
}