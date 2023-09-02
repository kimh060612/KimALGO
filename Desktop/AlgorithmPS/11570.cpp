#include <iostream>
#include <string.h>

using namespace std;
using ll = long long;

int N, A[2005];
ll DP[2005][2005];

int Abs(int x) { return x < 0 ? -x : x; }

ll dfs(int now, int san, int hee) {
    if (now == N + 1) return 0;
    ll &ret = DP[san][hee];
    if (ret != -1) return ret;

    ll snow = dfs(now + 1, now, hee) + (san == 0 ? 0 : Abs(A[now] - A[san]));
    ll hnow = dfs(now + 1, san, now) + (hee == 0 ? 0 : Abs(A[now] - A[hee]));
    return ret = min(snow, hnow);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    memset(DP, -1, sizeof(DP));
    ll ret = dfs(1, 0, 0);
    cout << ret << "\n";
    return 0;
}