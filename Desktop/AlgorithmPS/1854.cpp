#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e18

using namespace std;
using ll = long long;
using iip = pair<ll, ll>;
using iiip = pair<ll, iip>;

int N, M, K;
vector<iip> G[1005];
priority_queue<ll> dist[1005];

ll min(ll a, ll b) { return a < b ? a : b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back({ b, w });
    }
    priority_queue<iip> pq;
    pq.push({ 0, 1 });
    dist[1].push(0);

    while (!pq.empty()) {
        int x = pq.top().second;
        ll cost = -pq.top().first;
        pq.pop();

        for (auto node: G[x]) {
            int nx = node.first;
            ll nw = node.second + cost;

            if (dist[nx].size() < K) {
                dist[nx].push(nw); 
                pq.push({ -nw, nx });
            } else if (dist[nx].top() > nw) {
                dist[nx].pop();
                dist[nx].push(nw);
                pq.push({ -nw, nx });
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dist[i].size() != K) cout << "-1\n";
        else {
            cout << dist[i].top() << "\n";
        }
    }
    return 0;
}