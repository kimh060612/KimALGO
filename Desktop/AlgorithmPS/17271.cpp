#include <iostream>
#define MOD 1000000007

using namespace std;

int N, M;
int DP[10001];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++) DP[i] = 1;

    for (int i = M; i <= N; i++)
    {
        DP[i] = (DP[i - 1] + DP[i - M]) % MOD;
    }
    cout << DP[N] << endl;
    return 0;
}