#include <iostream>
#define MAX 105

using namespace std;

int N, DP[MAX][MAX], A[MAX][MAX];

int max(int a, int b) { return a > b ? a : b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        A[a][b] = 1;
        A[b][a] = 1;    
    }

    for (int j = 1; j <= 100; j++) {
        for (int i = j; i >= 1; i--) {
            for (int k = i; k < j; k++) DP[i][j] = max(DP[i][j], DP[i][k] + DP[k][j] + A[i][j]);
        }
    }

    cout << DP[1][100] << "\n";
    return 0;
}