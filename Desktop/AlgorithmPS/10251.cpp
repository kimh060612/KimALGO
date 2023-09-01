#include <iostream>
#include <string.h>
#define INF 987654321

using namespace std;

int N, M, L, G;
int FR[105][105], FD[105][105];
int DP[105][105][215][4];

int min(int a, int b) { return a < b ? a : b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> M >> N >> L >> G;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j < N; j++) {
                cin >> FR[i][j];
            }
        }
        for (int i = 1; i < M; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> FD[i][j];
            }
        }

        for (int i = 1; i <= M; i++) 
        {
            for (int j = 1; j <= N; j++) 
            {
                for (int k = 0; k <= 210; k++)
                {
                    DP[i][j][k][0] = INF;
                    DP[i][j][k][1] = INF;
                }
            }
        }
        
        int ret = INF;
        DP[1][1][0][0] = DP[1][1][0][1] = 0;
        for (int y = 1; y <= M; y++) {
            for (int x = 1; x <= N; x++) {
                for (int k = 0; k <= 210; k++) {
                    if (y + 1 <= M) {
                        DP[y + 1][x][k][0] = min(DP[y + 1][x][k][0], DP[y][x][k][0] + FD[y][x]);
                        DP[y + 1][x][k + 1][0] = min(DP[y + 1][x][k + 1][0], DP[y][x][k][1] + FD[y][x]);
                    }
                    if (x + 1 <= N) {
                        DP[y][x + 1][k][1] = min(DP[y][x + 1][k][1], DP[y][x][k][1] + FR[y][x]);
                        DP[y][x + 1][k + 1][1] = min(DP[y][x + 1][k + 1][1], DP[y][x][k][0] + FR[y][x]);
                    }
                }
            }
        }

        for(int k = 0; k <= 200; k++){
            if(DP[M][N][k][0] <= G){
                ret = min(ret, (N + M - 2) * L + k);
            }
            if(DP[M][N][k][1] <= G){
                ret = min(ret, (N + M - 2) * L + k);
            }
        }
        if (ret >= INF) cout << "-1\n";
        else cout << ret << "\n";
    }
    return 0;
}