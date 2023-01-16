#include <iostream>
#include <string.h>

using namespace std;
using ll = long long;

int N, A[25][25];
ll DP[2097153][25];

ll min(ll a, ll b) { return a < b ? a : b; }
int dfs(ll now, int nowWorker) {
    if (nowWorker == N) {
        for (int j = 1; j <= N; j++) {
            if (!(now & (1 << j))) return A[nowWorker][j];
        }
    }
    ll &ret = DP[now][nowWorker];
    if (ret != -1) return ret;

    ret = 1e17;
    for (int j = 1; j <= N; j++) {
        if (!(now & (1 << j))) {
            ret = min(ret, dfs(now | (1 << j), nowWorker + 1) + A[nowWorker][j]);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    memset(DP, -1, sizeof(DP));
    ll ans = dfs(0, 1);
    
    cout << ans << endl;
    return 0;
}