#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, v1, v2;
vector<pair<int, int>> E[801];
int Dis[801];

void dijkstra(int s)
{
    Dis[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({Dis[s], s});

    while (!pq.empty())
    {
        int X = pq.top().second;
        int distance = pq.top().first * (-1);
        pq.pop();

        if (Dis[X] < distance) continue;

        for (int i = 0; i < E[X].size(); i++)
        {
            int next = E[X][i].first;
            int nextDist = distance + E[X][i].second;
            if (nextDist < Dis[next])
            {
                Dis[next] = nextDist;
                pq.push({nextDist * (-1), next});
            }
        }   
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
        E[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    int o_v1, e_v1;
    int o_v2, e_v2;
    int v1_v2;

    for (int i = 1; i <= N; i++) Dis[i] = 987654321;
    dijkstra(v1);
    o_v1 = Dis[1];
    v1_v2 = Dis[v2];
    e_v1 = Dis[N];

    for (int i = 1; i <= N; i++) Dis[i] = 987654321;
    dijkstra(v2);
    o_v2 = Dis[1];
    e_v2 = Dis[N];

    if ((o_v1 == 987654321 && o_v2 == 987654321) || (e_v1 == 987654321 && e_v2 == 987654321) || v1_v2 == 987654321) cout << -1 << endl;
    else {
        int ans = min(o_v1 + e_v2, o_v2 + e_v1) + v1_v2;
        if (ans > 987654321 || ans < 0) cout << - 1 << endl;
        else cout << ans  << endl; 
    }
    
    return 0;
}