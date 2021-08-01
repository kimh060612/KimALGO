#include <iostream>
#define MOD 10007

using namespace std;

int N, DP[1000001];

int main()
{
    cin >> N;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;
    DP[4] = 4;
    for (int i = 5; i <= N; i++) DP[i] = (DP[i - 3] * 3) % MOD;
    cout << DP[N] << endl;
    return 0;   
}