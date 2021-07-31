#include <iostream>
#include <string>

using namespace std;

int N, M, A[1001][1001];
int DP[1001][1001];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        char S[1001];
        cin >> S;
        for (int j = 0; j < M; j++)
        {
            A[i][j + 1] = S[j] - 48;
            DP[i][j + 1] = A[i][j + 1];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (A[i][j] == 1) {
                if (DP[i - 1][j - 1] > 0 && DP[i - 1][j] > 0 && DP[i][j - 1] > 0) {
                    int small = DP[i - 1][j] < DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1];
                    small = small < DP[i - 1][j - 1] ? small : DP[i - 1][j - 1];
                    DP[i][j] = small + 1;
                }
            }
        }
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     for (int j = 1; j <= M; j++)
    //     {
    //         cout << DP[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            ans = max(ans, DP[i][j]);
        }
    }
    cout << ans * ans << endl;
    return 0;
}