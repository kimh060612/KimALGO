#include <iostream>
#include <string>
#define MOD 1000000007

using namespace std;

int N, DP[100001][6];
string UNIST = "UNIST";
string S[100001];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> S[i];
        for (int j = 1; j <= 5; j++) DP[i][j] = -1;
        DP[i][0] = 1;
    }

    int s_index = 0;
    for (int j = 1; j <= 5; j++)
    {
        if (S[1].substr(0, j) == UNIST.substr(0, j)) DP[1][j] = 1;
        else DP[1][j] = 0;
    }
    for (int i = 2; i <= N; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            int tmp = 0;
            for (int k = 1; k <= j; k++)
            {
                if (S[i].substr(0, j - k + 1) == UNIST.substr(k - 1, j - k + 1)) {
                    if (DP[i][k - 1] != -1) tmp = (tmp + DP[i][k - 1]) % MOD;
                }
            }
            DP[i][j] = (DP[i - 1][j] + tmp) % MOD;
        }
    }
    // int ans = 0;
    cout << DP[N][5] << endl;

    return 0;
}
