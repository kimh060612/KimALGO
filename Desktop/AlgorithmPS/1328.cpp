#include <iostream>
#define MAX 101
#define MOD 1000000007

using namespace std;
typedef long long ll;

int N, L, R;
ll DP[MAX][MAX][MAX];

int main()
{
    cin >> N >> L >> R;
    DP[1][1][1] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            for (int k = 1; k <= R; k++)
            {
                DP[i][j][k] = (DP[i - 1][j][k] * ((ll)(i - 2)) + DP[i - 1][j][k - 1] + DP[i - 1][j - 1][k]) % MOD;
            }
        }
    }
    cout << DP[N][L][R] << endl;
    return 0;
}