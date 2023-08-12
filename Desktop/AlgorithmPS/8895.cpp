#include <iostream>
#include <string.h>

using namespace std;
using ll = long long;

int N, L, R;
ll DP[25][25][25];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> L >> R;
        memset(DP, 0, sizeof(DP));
        DP[1][1][1] = 1;
        DP[2][1][2] = 1;
        DP[2][2][1] = 1;
        for (int i = 3; i <= N; i++) {
            for (int l = 1; l <= 20; l++) {
                for (int r = 1; r <= 20; r++) {
                    ll prev = DP[i - 1][l][r];
                    if (!prev) continue;
                    // Case 1: 양 끝에 i 길이 막대 추가
                    DP[i][l + 1][r] += prev;
                    DP[i][l][r + 1] += prev;
                    // Case 2: 중간에 i 길이 막대 추가
                    DP[i][l][r] += prev * (i - 2);
                }
            }
        }
        cout << DP[N][L][R] << "\n";
    }
    return 0;
}