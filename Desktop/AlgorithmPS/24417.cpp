#include <iostream>
#include <string.h>
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll fibo(ll k) 
{
    ll n1 = 1;
    ll n2 = 1, n3;
    for (int i = 3; i <= k; i++)
    {
        n3 = n2;
        n2 = (n2 + n1) % MOD;
        n1 = n3;
    }
    return n2;
}

int main()
{
    ll n;
    cin >> n;

    ll ans1 = fibo(n);
    ll ans2 = (n - 2) % MOD;
    cout << ans1 << " " << ans2 << endl;
    return 0;
}