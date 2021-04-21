#include <iostream>
#define MOD 1000000007

using namespace std;

long long DP[5001];

int main()
{
    int T;
    cin >> T;
    DP[0] = 1;
    DP[2] = 1;
    for (int i = 3; i <= 5000; i++)
    {
        for (int j = 2; j <= i ;j++)
        {
            DP[i] += DP[j - 2] * DP[i - j];
            DP[i] %= MOD;
        }
    }

    for (int t = 1; t <= T; t++) 
    {
        int a;
        cin >> a;
        cout << DP[a] << endl;
    }
    return 0;
}