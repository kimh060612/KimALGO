#include <iostream>
#define MAX 10001
#define INF 987654321

using namespace std;

int coin[101];
int DP[MAX];

int min(int a, int b) { return a < b ? a : b; }

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> coin[i];
    }

    for (int i = 1; i <= k; i++)DP[i] = INF;
    DP[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= coin[i])DP[j] = min(DP[j], DP[j - coin[i]] + 1);
        }   
    }

    if (DP[k] == INF) cout << -1 << endl;
    else cout << DP[k] << endl;

    return 0;
}