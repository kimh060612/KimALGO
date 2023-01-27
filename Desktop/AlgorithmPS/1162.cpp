#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;
using iip = pair<int, int>;
using iiip = pair<ll, iip>;

int N, M, K;
ll DP[10001][30];
vector<iip> G[10001];

ll min(ll a, ll b) { return a < b ? a : b; }
int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({ b, c });
        G[b].push_back({ a, c });
    }

    priority_queue<iiip> pq;
    pq.push({ 0, { 1, K } });
    for (int i = 1; i <= N; i++)
        for (int k = 0; k <= K; k++) 
            DP[i][k] = 9223372036854775800;

    DP[1][0] = 0;

    while (!pq.empty()) {
        ll cost = (-1) * pq.top().first;
        int x = pq.top().second.first;
        int wrap = pq.top().second.second;
        pq.pop();

        if(cost > DP[x][wrap]) continue;

        for (iip nx: G[x]) {
            int next = nx.first;
            ll nextCost = cost + nx.second;
            if (wrap > 0 && DP[next][wrap - 1] > cost) {
                DP[next][wrap - 1] = cost;
                pq.push({
                    (-1) * cost,
                    {
                        next,
                        wrap - 1
                    }
                });
            }
            if (wrap >= 0 && DP[next][wrap] > nextCost) {
                DP[next][wrap] = nextCost;
                pq.push({
                    (-1) * nextCost,
                    {
                        next,
                        wrap
                    }
                });
            }
        }
    }

    ll ans = 9223372036854775800;
    for (int i = 0; i < K; i++) ans = min(ans, DP[N][i]);

    std::cout << ans << "\n";
    return 0;
}