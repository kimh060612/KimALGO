#include <iostream>
#include <string.h>
#define MAX 500000

using namespace std;

int C, D, M;
int DP[MAX + 1], A[51][20];

int max(int a, int b) { return a > b ? a : b; }

int main() {

    cin >> C >> D >> M;
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= D; j++) {
            cin >> A[i][j];
        }
    }

    for (int d = 2; d <= D; d++) {
        memset(DP, 0, sizeof(DP));
        for (int i = 1; i <= C; i++) {
            for (int k = 1; k <= M; k++) {
                if (k - A[i][d - 1] < 0) continue;
                DP[k] = max(DP[k], DP[k - A[i][d - 1]] + (A[i][d] - A[i][d - 1]));
            }
        }
        M += DP[M];
    }

    cout << M << "\n";
    return 0;
}