#include <iostream>
#define MOD 1000000003

using namespace std;

int N, K;
int DP[1001][1001];

int main()
{
    cin >> N >> K;
    for (int i = 0; i <= N; i++) 
    {
        DP[i][1] = i;
        DP[i][0] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= N; j++) 
        {
            DP[i][j] = (DP[i - 2][j - 1] + DP[i - 1][j]) % MOD;
        }
    }

    int ans = (DP[N - 1][K] + DP[N - 3][K - 1]) % MOD;
    cout << ans << endl;
    return 0;
}