#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

int N, K;
string B[20];
int A[20], len[20];
ll DP[(1 << 16)][102];
ll ten[51];

int isMultiplication(string s) 
{
    int l = s.length();
    int mod = 0;
    for (int i = 0; i < l; i++)
    {
        int k = s[i] - '0';
        mod = (mod * 10 + k) % K;
    }
    return mod;
}

ll gcd(ll a, ll b)
{
    if (b > a) swap(a, b);
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> B[i];
        len[i] = B[i].length();
    }
    cin >> K;
    for (int i = 1; i <= N; i++)A[i] = isMultiplication(B[i]);

    ten[0] = 1;
    for (int i = 1; i <= 51; i++)
    {
        ten[i] = (ten[i - 1] * 10) % K;
    }

    DP[0][0] = 1;
    for (int i = 0; i < (1 << N); i++)
    {
        for (int k = 0; k < K; k++)
        {
            for (int j = 0; j < N; j++)
            {
                if ((i & (1 << j)) == 0)
                {
                    int next = ((k * ten[len[j + 1]]) % K + A[j + 1]) % K;
                    DP[i | (1 << j)][next] += DP[i][k];
                }
            }
        }
    }

    ll fac = 1;
    for (int i = 1; i <= N; i++) fac *= i;

    ll GCD = gcd(DP[(1 << N) - 1][0], fac);
    ll u = DP[(1 << N) - 1][0] / GCD;
    ll l = fac / GCD;
    cout << u << "/" << l << endl;
    return 0;
}