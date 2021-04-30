#include <iostream>
#include <string.h>
using namespace std;

int DP[100001];
int coin[2] = {2, 5};

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) DP[i] = 987654321;
    DP[2] = 1;
    DP[4] = 2;
    DP[5] = 1;
    DP[6] = 3;
    DP[7] = 2;
    for (int i = 8; i <= N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i - coin[j] >= 0) DP[i] = min(DP[i], DP[i - coin[j]] + 1);
        }
    }
    if (DP[N] == 987654321)cout << -1 << endl;
    else cout << DP[N] << endl;
    return 0;
}