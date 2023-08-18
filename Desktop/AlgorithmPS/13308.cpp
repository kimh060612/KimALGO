#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
#define INF 1e18

using namespace std;
using ll = long long;
using llp = pair<ll, ll>;

struct Node
{
    int node;
    ll dist, cost;
    Node(int _x, ll _dist, ll _cost): node(_x), dist(_dist), cost(_cost) {}
    bool operator<(const Node &node) const {
        if (node.dist == this->dist) return node.cost < this->cost;
        return node.dist < this->dist;
    }
};

// Dist[i][j]: i에서 출발할때 j까지 가는데 걸리는 최소 거리
// DP[i][j]: i에서 출발할때 j까지 가는데 드는 최소 비용
ll N, C[2501], M, check[2501][2501];
vector<llp> G[2501];

ll min(ll a, ll b) { return a < b ? a : b; }

void dijkstra(int s) {
    priority_queue<Node> pq;
    pq.push(Node(s, 0, C[s]));

    while (!pq.empty()) {
        ll dist = pq.top().dist;
        ll cost = pq.top().cost;
        int x = pq.top().node;
        pq.pop();
        if (check[x][cost]) continue;
        if (x == N) {
            cout << dist << "\n";
            return;
        }

        check[x][cost] = 1;
        for (auto nxnode: G[x]) {
            int nx = nxnode.first;
            ll moil = min(cost, C[nx]);
            ll nxcost = dist + cost * nxnode.second;
            pq.push(Node(nx, nxcost, moil));
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> C[i];
    for (int i = 1; i <= M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({ b, w });
        G[b].push_back({ a, w });
    }

    dijkstra(1);
    return 0;
}