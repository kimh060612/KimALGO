#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;
using iip = pair<int, int>;

int N, M;
vector<pair<int ,int>> V[1001];
vector<iip> check[1001];
int blackEdge[1001][1001];
int safeDist[1001], minDist[1001];

void findShortestPath() {
    priority_queue<iip> pq;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int x = pq.top().second;
        int cost = (-1) * pq.top().first;
        pq.pop();

        for (auto elem : V[x]) {
            int next = elem.first;
            int next_cost = cost + elem.second;
            if (minDist[next] > next_cost) {
                minDist[next] = next_cost;
                pq.push({ (-1) * next_cost, next });
                if (check[next].size() != 0) check[next].clear();
                check[next].push_back({ x, elem.second });
            }
        }
    }

    queue<int> Q;
    Q.push(N);

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();

        for (auto elem: check[x]) {
            int next = elem.first;
            int w = elem.second;
            blackEdge[x][next] = w;
            blackEdge[next][x] = w;
            Q.push(next);
        }
    }
}

void findSateShortestPath() {
    priority_queue<iip> pq;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int x = pq.top().second;
        int cost = (-1) * pq.top().first;
        pq.pop();

        for (auto elem : V[x]) {
            int next = elem.first;
            int next_cost = cost + elem.second;
            if (safeDist[next] > next_cost && blackEdge[x][next] != elem.second) {
                safeDist[next] = next_cost;
                pq.push({ (-1) * next_cost, next });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        V[a].push_back({ b, c });
        V[b].push_back({ a, c });
    }
    for (int i = 2; i <= N; i++) minDist[i] = INF;
    for (int i = 2; i <= N; i++) safeDist[i] = INF;

    findShortestPath();
    findSateShortestPath();

    cout << safeDist[N] << endl;

    return 0;
}