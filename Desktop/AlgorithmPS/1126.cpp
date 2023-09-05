#include <iostream>
#include <string.h>
#define INF 987654321
#define MAX 500005

using namespace std;

int N, A[55], DP[55][MAX];

int max(int a, int b) { return a > b ? a : b; }

int dfs(int index, int diff) {
    if (diff > (MAX / 2)) return -INF;
    if (index == N + 1 && diff) return -INF;
    if (index == N + 1 && diff == 0) return 0;
    int &ret = DP[index][diff];
    if (ret != -1) return ret;

    ret = -INF;
    int contain = dfs(index + 1, diff + A[index]);
    int ncontain = dfs(index + 1, diff);
    if (diff > A[index]) ret = max(ret, A[index] + dfs(index + 1, diff - A[index]));
    else ret = max(ret, diff + dfs(index + 1, A[index] - diff));
    return ret = max(ret, max(contain, ncontain));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    memset(DP, -1, sizeof(DP));

    int ret = dfs(1, 0);
    if (ret) cout << ret << "\n";
    else cout << -1 << "\n";
    return 0;
}