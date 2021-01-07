// #include <bits/stdc++.h>

// using namespace std;
// int n, m, dept, dest;
// vector<vector<pair<int, int>>> adj;
// vector<int> cost_cache;
// vector<bool> visited;
// vector<vector<bool>> edge_visited;
// int dfs(int here)
// {
//     if (here == dest)
//         return 0;
//     for (int i = 0; i < adj[here].size(); ++i)
//         if (!visited[adj[here][i].first])
//             cost_cache[here] = max(cost_cache[here], dfs(adj[here][i].first) + adj[here][i].second);
//         else
//             cost_cache[here] = max(cost_cache[here], cost_cache[adj[here][i].first] + adj[here][i].second);
//     visited[here] = true;
//     return cost_cache[here];
// }
// int dfs2(int here, int cost, int max_cost)
// {
//     int ret = 0;
//     if (cost + cost_cache[here] == max_cost)
//         ret += 1;
//     else
//         return 0;
//     for (int i = 0; i < adj[here].size(); ++i)
//         if (!edge_visited[here][adj[here][i].first])
//         {
//             ret += dfs2(adj[here][i].first, cost + adj[here][i].second, max_cost);
//             edge_visited[here][adj[here][i].first] = true;
//         }
//     return ret;
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin >> n >> m;
//     adj = vector<vector<pair<int, int>>>(n + 1);
//     cost_cache = vector<int>(n + 1, 0);
//     visited = vector<bool>(n + 1, 0);
//     edge_visited = vector<vector<bool>>(n + 1, vector<bool>(n + 1, 0));
//     while (m--)
//     {
//         int u, v, c;
//         cin >> u >> v >> c;
//         adj[u].push_back(make_pair(v, c));
//     }
//     cin >> dept >> dest;
//     int max_cost = dfs(dept);
//     int road = dfs2(dept, 0, max_cost);
//     cout << max_cost << "\n"
//          << road - 1;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <string.h>
// #include <stdlib.h>
// #define MAX 10001

// using namespace std;

// vector<pair<int, int>> edge[MAX];
// vector<vector<bool>> edge_visited;
// int visited[MAX], cache[MAX], MaxRoad = 0;
// int N, M;

// int max(int a, int b) { return a > b ? a : b; }

// void Search(int s, int e)
// {
//     if (s == e)
//         return;
//     visited[s] = 1;
//     for (int i = 0; i < edge[s].size(); i++)
//     {
//         int next_node = edge[s][i].first;
//         int wegith = edge[s][i].second;

//         if (cache[next_node] > wegith)
//         {
//             cache[next_node] = max(cache[next_node], cache[s] + wegith);
//             Search(next_node, e);
//         }
//     }
// }

// void count(int s, int e)
// {
//     visited[e] = 1;
//     if (s == e)return;
//     for (int i = 0; i < edge[e].size(); i++)
//     {
//         int prev = edge[e][i].first;
//         int weight = edge[e][i].second;
//         if (cache[e] - weight == cache[prev])
//         {
//             MaxRoad++;
//             if (!visited[prev])
//             {
//                 visited[prev] = 1;
//                 count(s, prev);
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> N >> M;
//     for (int i = 1; i <= M; i++)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         edge[a].push_back(make_pair(b, w));
//     }
//     edge_visited = vector<vector<bool>>(N+1, vector<bool>(N+1, 0));
//     int start, end;
//     cin >> start >> end;
//     Search(start, end);
//     memset(visited, 0, sizeof(visited));
//     count(start, end);
//     cout << cache[end] << endl;
//     cout << MaxRoad << endl;

//     return 0;
// }