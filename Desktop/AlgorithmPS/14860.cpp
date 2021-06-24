#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>
#define MOD 1000000007

using namespace std;
typedef long long ll;

int isPrime[15000001], N, M;

void makePrimeArr()
{
    isPrime[1] = -1;
    for (int i = 2; i <= 15000000; i++) isPrime[i] = i;
    int n = (int)sqrt(15000000);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i] == i)
        {
            for (int j = i * i; j <= 15000000; j += i) {
                if (isPrime[j] == j) isPrime[j] = i;
            }
        }
    }
}

int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a%b) : a;
}

ll getPower(ll a, ll b)
{
    long long res = 1; 
    while (b > 0) {
        if (b & 1){
            res *= a;
            res %= MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    cin >> N >> M;
    memset(isPrime, 1, sizeof(isPrime));
    makePrimeArr();
    vector<int> p;
    for (int i = 2; i <= min(N, M); i++)
    {
        if(isPrime[i] == i)p.push_back(i);
    }
    ll ans = 1;
    for (int i = 0; i < p.size(); i++)
    {
        ll num = 0;
        for (ll k = p[i]; k <= N; k *= p[i]) num += (N / k) * (M / k);
        ans = (ans * getPower(p[i], num)) % MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}