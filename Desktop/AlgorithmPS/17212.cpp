#include <iostream>

using namespace std;

int DP[100001];
int C[5] = {0, 1, 2, 5, 7};

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) DP[i] = 987654321;

    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 2;
    DP[4] = 2;
    DP[5] = 1;
    DP[6] = 2;
    DP[7] = 1;
    for (int i = 8; i <= n; i++)
    {
        if (i % 7 == 0) DP[i] = i / 7;
        else {
            for (int j = 1; j <= 4; j++)
            {
                if (i - j >= 1) DP[i] = min(DP[i], DP[i - C[j]] + 1);
            }
        }
    }

    cout << DP[n] << endl;
    return 0;
}