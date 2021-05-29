#include <iostream>

using namespace std;

long long N, K, M;
int nCr[2001][2001];

int main()
{
    cin >> N >> K >> M;

    for(int i = 0; i <= M; i++)
    { 
        nCr[i][0] = 1; 
        for(int j = 1; j <= i; j++) nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j])%M; 
    }

    long long n = N, k = K;
    long long ans = 1;
    while (n != 0 || k != 0) 
    {
        int mod_n = n % M;
        int mod_k = k % M;
        ans *= nCr[mod_n][mod_k];
        ans %= M;
        n = n / M;
        k = k / M;
    }

    cout << ans << endl;

    return 0;
}