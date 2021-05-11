#include <iostream>
#define MOD 1000000009

using namespace std;

long long DP[1000001];

int main()
{
    int T;
    cin >> T;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;
    for (int i = 4 ; i <= 1000001; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3]) % MOD;
    }
    for (int t = 1; t <= T; t++)
    {
        int a;
        cin >> a;
        cout << DP[a] << endl;
    }
    return 0;
}