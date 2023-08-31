#include <iostream>
#define MAX 10000
#define MOD 1000000007

using namespace std;
using ll = long long;

int N, H[MAX + 5];
ll DP[3][MAX + 5];

int min(int a, int b) { return a < b ? a : b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> H[i];

    DP[0][0] = 1;
    DP[1][0] = 1;
    for (int i = 1; i <= N; i++) {
        int idx = i%2, pre = (idx + 1) % 2;;
        if(H[i] > min(i - 1, N - i)){
            cout << 0 << '\n';
            return 0;
        }
        for(int j = 0; j < MAX / 2; j++) DP[idx][j] = 0;
        if (H[i] == -1) {
            for(int j = 0; j < MAX / 2; j++){
                if(j > min(i - 1, N - i)) break;
                for(int k = -1; k < 2; k++){
                    int prev = j + k;
                    if(prev < 0) continue;
                    DP[idx][j] = (DP[idx][j] + DP[pre][prev]) % MOD;
                }
            }
        } else {    
            for(int k = -1; k < 2; k++){
                int prev = H[i] + k;
                if(prev < 0) continue;
                DP[idx][H[i]] = (DP[idx][H[i]] + DP[pre][prev]) % MOD;
            }
        }
        if(i == N) cout << DP[idx][0] % MOD << "\n";
    }

    return 0;
}