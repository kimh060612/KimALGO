#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
using ll = long long;
int N, M, A[10001];
ll DP[2][10001];
ll DP1[10001], DP2[10001];

ll min(ll a, ll b) { return a < b ? a : b; }
// ll dfs(int n, int m) {
//     ll &ret = DP[n][m];
//     if (ret != -1) return ret;
//     if (m == 0) {
//         if (N - n > M) return 1e18;
//         return 0;
//     }

//     ret = 1e18;
//     for (int i = n + 1; i < N; i++) {
//         if (i - n > M) break; 
//         ret = min(ret, dfs(i, m - 1) + A[i]);
//     }
//     return ret;
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for (int i = 1; i < N; i++) {
        int a;
        cin >> a;
        for (int j = i; j > 1; j--) DP2[j] = min(DP1[j - 1], DP1[i + 1 - j] + a);
        DP2[1] = a;
        memcpy(DP1, DP2, sizeof(ll) * (i + 1));
    }
    // 1개를 쪼개면 중간만 쪼갤 수 있다. ==> base case!
    // 2 ~ M - 1개를 쪼개는 방향으로 가야한다.

    // i개를 쪼개는 상황이면 i - 1개의 위치를 결정하면 남은 1개는 자동으로 결정된다.

    cout << DP1[N / 2] << endl;
    return 0;
}
