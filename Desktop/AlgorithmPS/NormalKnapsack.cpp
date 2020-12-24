#include <iostream>
#define MAX 100

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int Weight[MAX + 1], Price[MAX+1];
int DP[MAX + 1][MAX*1000 + 1];
int n, k;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int w, v;
        cin >> w >> v;
        Weight[i] = w;
        Price[i] = v;
    }
    int Max = -0x7fffffff;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (Weight[i] > j)DP[i][j] = DP[i - 1][j];
            else DP[i][j] = max(Price[i] + DP[i-1][j - Weight[i]], DP[i - 1][j]);
        }   
    }

    cout << DP[n][k] << endl;

    return 0;
}