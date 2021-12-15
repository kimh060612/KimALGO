#include <iostream>

using namespace std;

long long DP[10000001];

int main()
{
    int n;
    cin >> n;
    DP[2] = 2;
    DP[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2])%10;
    }
    cout << DP[n] % 10 << endl;
    return 0;
}