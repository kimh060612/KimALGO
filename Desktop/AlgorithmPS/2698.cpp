#include <iostream>

using namespace std;

int DP[101][101][3];
int N, K;

int main()
{
    DP[1][0][1] = 1;
    DP[1][0][0] = 1;

    for (int i = 2; i <= 100; i++)
    {
        for (int j = 0; j < i; j++)
        {
            DP[i][j][1] += DP[i - 1][j][0] + DP[i - 1][j - 1][1];
            DP[i][j][0] += DP[i - 1][j][0] + DP[i - 1][j][1];
        }
    }

    int t;
    cin >> t;
    while (t--) 
    {
        cin >> N >> K;
        cout << DP[N][K][0] + DP[N][K][1] << endl;
    }
    return 0;
}