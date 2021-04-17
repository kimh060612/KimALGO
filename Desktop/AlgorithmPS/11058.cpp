#include <iostream>

using namespace std;

long long N, DP[101];

int main()
{
    cin >> N;
    DP[1] = 1; DP[2] = 2; DP[3] = 3; DP[4] = 4; DP[5] = 5; DP[6] = 6; 
    for (int i = 7; i <= N; i++) 
    {
        for (int j = 3; i > j; j++) 
        {
            DP[i] = max(DP[i], DP[i - j] * (j - 1));
        }
    }
    cout << DP[N] << endl;
    return 0;
}