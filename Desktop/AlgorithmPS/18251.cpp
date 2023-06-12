#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#define INF 9876543210

using namespace std;
using ll = long long;
using llp = pair<ll, ll>;

int N, H;
ll T[300000];
ll DP[300000][35];
vector<llp> X, Y[35];

ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

void dfs(int now, int depth) {
    if (T[now] == INF) return;
    int left = 2 * now, right = 2 * now + 1;

    dfs(left, depth + 1);
    X.push_back({ now, depth });
    Y[depth].push_back({ now, T[now] });
    dfs(right, depth + 1);
}

int main()
{
    cin >> N;
    H = (int)ceil(log2(N + 1));
    fill(T + 1, T + 262144, INF);
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
    }

    dfs(1, 1);
    
    ll ret = -INF;
    DP[1][H] = T[X[0].first];
    for (int i = 1; i < N; i++) {
        int w = T[X[i].first];
        int y = X[i].second;
        for (int h = 1; h <= H; h++) {
            
        }
    }
    cout << ret << "\n";
    return 0;
}