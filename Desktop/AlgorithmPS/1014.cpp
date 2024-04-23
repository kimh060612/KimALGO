#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int M, N;
int A[20][20], DP[20][3000]; // DP[i]: i번째 행에 배치할 수 있는 자리의 형태

int count(int x) {
    int ret = 0;
    for (int i = 1; i <= M; i++) {
        if (x & (1 << i)) ret ++;
    }
    return ret;
}

int dfs(int y, int prev_row) {
    if (y > N) return 0;

    for (int i = 0; i <= (1 << M); i++) { // 가능한 모든 자리배치
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> c;
    while (c--) {
        memset(A, 0, sizeof(A));
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            string t;
            cin >> t;
            for (int j = 0; j < M; j++) {
                if (t[j] == 'x') A[i][j + 1] = 0;
                if (t[j] == '.') A[i][j + 1] = 1;
            }
        }
        int ret = dfs(1, 0);
        
    }
    
    return 0;
}