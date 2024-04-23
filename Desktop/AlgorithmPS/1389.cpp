#include <iostream>
#define INF 987654321

using namespace std;

int N, M;
int W[105][105];
int DP[105][105], KB[105];

int min(int a, int b) { return a < b ? a : b; }

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            W[i][j] = INF;
        }
    }
    for (int i = 1; i <= N; i++) W[i][i] = 0;
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        W[a][b] = 1;
        W[b][a] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            DP[i][j] = W[i][j];
        }
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
            }
        }
    }

    int ret = INF, ans = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            KB[i] += DP[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        if (ret > KB[i]) {
            ans = i;
            ret = KB[i];
        }
    }
    cout << ans << "\n";
    return 0;
}