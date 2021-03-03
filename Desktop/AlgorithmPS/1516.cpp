#include <iostream>
#define MAX 1001

using namespace std;

int A[MAX][5], DP[MAX][5];
int N;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> A[i][j];
        }
    }

    int ans = 1000*1000 + 1;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (i == j)DP[1][j] = A[1][j];
            else DP[1][j] = 1000*1000 + 1;
        }
        for (int j = 2; j <= N; j++)
        {
            DP[j][1] = min(DP[j - 1][2], DP[j - 1][3]) + A[j][1];
            DP[j][2] = min(DP[j - 1][1], DP[j - 1][3]) + A[j][2];
            DP[j][3] = min(DP[j - 1][1], DP[j - 1][2]) + A[j][3];
        }
        for (int j = 1; j <= 3; j++)
        {
            if (j == i)continue;
            ans = min(ans, DP[N][j]);
        }
    }

    cout << ans << endl;
    return 0;
}