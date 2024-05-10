#include <iostream>
#include <vector>
#include <string.h>
#define MAX 10000
#define INF 987654321

using namespace std;
using ll = long long;

int N, M;
vector<ll> V, C;
ll DP[2005][10005];

ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    V.push_back(0);
    C.push_back(0);
    int cnt = 1;
    while (cnt <= N) {
        ll v, c, K;
        cin >> v >> c >> K;
        ll k = 1;
        while (K > 0) {
            ll tmp = min(k, K);
            V.push_back(tmp * v);
            C.push_back(tmp * c);
            K -= k;
            k *= 2;
        }
        cnt ++;
    }
    N = V.size() - 1;

    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= M; w++) {
            if (w < V[i]) {
                DP[i][w] = DP[i - 1][w];
            } else {
                DP[i][w] = max(DP[i - 1][w], DP[i - 1][w - V[i]] + C[i]);
            }
        }
    }
    
    cout << DP[N][M] << "\n";
    return 0;
}