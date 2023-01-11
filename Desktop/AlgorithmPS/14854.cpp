#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MOD 142857
#define MAX 1e9 + 1

using namespace std;
using ll = long long;
using plll = pair<ll, pair<ll, ll>>;
using pll = pair<ll, ll>;
ll N, K;
ll cache[41][41];

plll xGCD(ll a, ll b) {
    if (b == 0) return { a, { 1, 0 } };
    plll ret = xGCD(b, a % b);
    ll g, x, y;
    g = ret.first;
    tie(x, y) = ret.second;
    return { g, { y, x - (a / b) * y } };
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

ll nCkPrime(ll n, ll k, ll p) {
    ll ret = 1;
    while(n || k) {
        ret *= cache[n%p][k%p] % p;
        n /= p; k /= p; ret %= p;
    }
    return ret;
}

ll CRT(vector<ll> x, vector<ll> p) {
    ll n = x.size();
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        ll M_i = MOD / p[i];
        plll g = xGCD(M_i, p[i]);
        if (g.first > 1) return -1;
        ll p_inv = (g.second.first + p[i]) % p[i];
        ret = (ret + x[i] * (p_inv % p[i]) * M_i) % MOD;
    }
    return ret;
}

ll fpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b /= 2;
    }
    return res;
}

ll factorialPrime(ll n, ll p, int index, int f) {
    ll x_j = (n / fpow(p, (ll)index)) % fpow(p, f);
    ll res = 1;
    for (int i = 1; i <= x_j; i++) {
        if (i % p == 0) continue;
        res *= i;
    }
    return res;
}

void getPbaseNum(ll n, ll p, vector<ll> &res) {
    ll n_tmp = n;
    while (n_tmp > 0) {
        res.push_back(n_tmp % p);
        n_tmp /= p;
    }
}

ll granvile(ll n, ll k, ll p, ll f) {
    ll nk = n - k;
    vector<ll> n_p, k_p, nk_p;
    getPbaseNum(n, p, n_p);
    getPbaseNum(k, p, k_p);
    getPbaseNum(nk, p, nk_p);

    int e_f = 0, e_0 = 0;
    for (int i = f - 1; i < n_p.size(); i++)
    {
        ll k_p_i = i < k_p.size() ? k_p[i] : 0; 
        if (k_p_i > n_p[i]) e_f ++;
    }
    for (int i = 0; i < n_p.size(); i++)
    {
        ll k_p_i = i < k_p.size() ? k_p[i] : 0; 
        if (k_p_i > n_p[i]) e_0 ++;
    }
        
    int sw = e_f % 2 == 0 ? 1 : -1;
    
    ll res = 1;
    for (int d = 0; d < n_p.size(); d++) {
        res *= factorialPrime(n, p, d, f);
        res /= factorialPrime(k, p, d, f);
        res /= factorialPrime(nk, p, d, f);
    }
    res *= sw;
    ll mod = fpow(p, f);
    res = (res + mod) % mod;
    res = (res * fpow(p, e_0)) % mod;
    return res;
}

int main()
{
    ll t;
    cin >> t;
    memset(cache, 0, sizeof(cache));

    cache[1][1] = 1;
    cache[1][0] = 1;
    for (int i = 2; i <= 40; i++) {
        for (int j = 0; j <= i; j++) {
            cache[i][j] = cache[i - 1][j] + cache[i - 1][j - 1];
        }
    }

    while (t--) {
        cin >> N >> K;
        // 3^3, 11, 13, 37
        ll nCk3 = nCkPrime(N, K, 3); // x = a (mod 3)
        ll nCk11 = nCkPrime(N, K, 11);
        ll nCk13 = nCkPrime(N, K, 13);
        ll nCk37 = nCkPrime(N, K, 37);
        ll nCk27 = granvile(N, K, 3, 3);
        vector<ll> primes = { 27, 11, 13, 37 };
        vector<ll> X = { nCk27, nCk11, nCk13, nCk37 };
        ll res = CRT(X, primes);
        cout << res << endl;
    }
    return 0;
}
