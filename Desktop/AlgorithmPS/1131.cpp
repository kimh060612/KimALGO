#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

int A, B, K;
ll DP[1000001];
int visited[1000001];

ll min(ll a, ll b) { return a < b ? a : b; }

ll calc(ll n)
{
    ll ans = 0;
    while (n > 0)
    {
        ll num = 1;
        for (int i = 1; i <= K; i++) num *= (n % 10);
        ans += num;
        n /= 10;
    }
    return ans;
}

ll Search(ll x)
{
    ll k = calc(x);
    if (x > 1000000) return Search(k);
    if (visited[x]) {
        ll i = k, Mans = 2e18;
        while (i != x) 
        {
            Mans = min(Mans, i);
            i = calc(i);
        }
        return Mans < x ? Mans : x;
    }
    if (DP[x]) return DP[x];
    visited[x] = 1;
    DP[x] = min(Search(k), x);
    visited[x] = 0;
    return DP[x];
}

int main()
{
    cin >> A >> B >> K;
    DP[1] = 1;
    ll ans = 0;
    for (ll i = A; i <= B; i++) 
    {
        ans += Search(i);
    }

    cout << ans << endl;
    return 0;
}