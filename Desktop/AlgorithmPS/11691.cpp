#include <iostream>
#include <cmath>
#include <vector>
#define M 1000000007
#define MAX 1000000

using namespace std;
using ll = long long;

ll N;
ll f[MAX + 5];
int mu[MAX + 5], phi[MAX + 5];


ll go[1000001];
//1<=a<b<=n에 대해서, gcd(a,b) = 1인 pair쌍의 ab 값의 합.
ll dp[1000001];
vector <ll> v;
vector <ll> bit[128];

ll calc(ll x)
{
    //a = x, 1<=b<=x
    ll tot = (x*(x+1))/2;
    ll sz = (ll)v.size();
    for(ll i=1;i<(1<<sz);i++)
    {
        ll rr = 1, cou = (ll)bit[i].size();
        for(ll j=0;j<cou;j++)
            rr = rr * v[bit[i][j]];
        ll u = x/rr;
        ll T = rr*((u*(u+1))/2);
        if(cou%2)
            tot = tot - T;
        else
            tot = tot + T;
    }
    return tot*x;
}
void init2()
{
    for(ll i=2;i<=1000000;i++)
    {
        if(go[i])
            continue;
        for(ll j=i;j<=1000000;j=j+i)
            go[j] = i;
    }
    for(ll i=1;i<128;i++)
    {
        for(ll j=0;j<7;j++)
        {
            if(i&(1<<j))
                bit[i].push_back(j);
        }
    }
}
void bunhae(ll x)
{
    ll cur = x;
    v.clear();
    while(cur!=1)
    {
        if(v.size() == 0 || v[v.size()-1]!=go[cur])
            v.push_back(go[cur]); 
        cur = cur/go[cur];
    }
}

ll solution(ll n) {
    ll ans=0; init2();
    for(ll i=2;i<=n;i++)
    {
        bunhae(i);
        dp[i] = dp[i-1] + calc(i); dp[i]%=M;
    }
    for(ll gcd=1;gcd<=n;gcd++)
    {
        ans = ans + gcd*dp[n/gcd]; ans = ans%M;
    }
    return ans;
}

int main(void)
{
    unsigned long long n; 
    cin >> n;
    cout << solution(n) << "\n";
    return 0;
}