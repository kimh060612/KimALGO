#include <iostream>
#define MOD 10007

using namespace std;
typedef long long ll;

ll DP[1001][1001];
int N, K;

ll nCr(int n, int r)
{
    if (n == r || r == 0) return 1;
    ll &ret = DP[n][r];
    if (ret != 0) return ret;
    ret = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % MOD;
    return ret;
}

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= 1000; i++) {
        DP[i][0] = 1;
        DP[i][i] = 1;
    }
    cout << nCr(N, K) << endl;
    return 0;
}