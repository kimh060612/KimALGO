#include <iostream>
#include <string.h>
#define MOD 1000000

using namespace std;

int N;
int DP[3][101][101];
int check[101];

int dfs(int prev, int prevState, int depth) {
    if (depth == N) return 1;
    int &ret = DP[prevState][prev][depth];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 1; i <= N; i++) {
        if (!check[i] && ((prevState && i > prev) || (!prevState && i < prev))) {
            check[i] = 1;
            ret = (ret + dfs(i, !prevState, depth + 1)) % MOD;
            check[i] = 0;
        }
    }
    return ret;
}

int main()
{
    cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return 0;   
    }
    if (N == 2) {
        cout << 2 << endl;
        return 0;
    }
    memset(DP, -1, sizeof(DP));

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        check[i] = 1;
        for (int j = 1; j <= N; j++) {
            if (j == i) continue;
            check[j] = 1;
            ans = (ans + dfs(j, i > j, 2)) % MOD;
            check[j] = 0;
        }
        check[i] = 0;
    }

    cout << ans << endl;
    return 0;
}