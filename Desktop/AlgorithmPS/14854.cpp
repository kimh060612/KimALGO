#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MOD 142857

using namespace std;
using ll = long long;
using plll = pair<ll, pair<ll, ll>>;
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

ll getModuloInverse(ll n, ll mod) {
    plll g = xGCD(n, mod);
    if (g.first > 1) return -1;
    ll p_inv = (g.second.first + mod) % mod;
    return p_inv;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

ll nCkPrime(ll n, ll k, ll p) {
    ll ret = 1;
    while(n || k) {
        ret = (ret * cache[n % p][k % p] % p) % p;
        n /= p;
        k /= p;
    }
    return ret;
}

ll CRT(vector<ll> x, vector<ll> p) {
    ll n = x.size();
    ll ret = 0;
    for (int i = 0; i < n; i++) {
        ll M_i = MOD / p[i];
        ll p_inv = getModuloInverse(M_i, p[i]);
        ret = (ret + (x[i] * (p_inv % p[i]) * M_i) % MOD) % MOD;
    }
    return ret;
}

ll fpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b % 2 == 1) {
            res *= a;
        }
        a *= a;
        b /= 2;
    }
    return res;
}

ll factorialPrime(ll n, ll p, ll index, int f) {
    ll x_j = (n / fpow(p, index)) % fpow(p, f);
    
    ll res = 1;
    for (ll i = 1; i <= x_j; i++) {
        if (i % p == 0) continue;
        res = (res * i) % fpow(p, f);
    }
    return res;
}

ll getPbaseNum(ll n, ll p, ll f, vector<ll> &res) {
    ll n_tmp = n, index = 0;
    while (n_tmp > 0 || index <= f - 1) {
        res.push_back(n_tmp % p);
        n_tmp /= p;
        index ++;
    }
    return index - 1;
}

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

ll granvile(ll n, ll k, ll p, ll f) {
    ll nk = n - k;
    vector<ll> n_p, k_p, nk_p;
    ll d_n = getPbaseNum(n, p, f, n_p);
    ll d_k = getPbaseNum(k, p, f, k_p); // 논문에서의 m
    ll d_nk = getPbaseNum(nk, p, f, nk_p); // 논문에서의 r

    int d = max(d_n, max(d_k, d_nk));
    int e_f = 0, e_0 = 0;
    int prev_carry = 0;
    vector<bool> hasCarry(d + 1);
    for (int i = 0; i <= d; i++) {
        ll nkpi = i >= nk_p.size() ? 0 : nk_p[i];
        ll kpi = i >= k_p.size() ? 0 : k_p[i];
        ll val = nkpi + kpi + prev_carry;
        if (val >= p) {
            hasCarry[i] = true;
            prev_carry = 1;
        } else {
            hasCarry[i] = false;
            prev_carry = 0;
        }
    }
    for (int i = f - 1; i <= d; i++) 
        e_f += hasCarry[i] ? 1 : 0;
    for (int i = 0; i <= d; i++) 
        e_0 += hasCarry[i] ? 1 : 0;
        
    int sw = e_f % 2 == 0 ? 1 : -1;
    ll res = 1;
    ll mod = fpow(p, f);
    for (int _d = 0; _d <= n_p.size(); _d++) {
        ll Nj = factorialPrime(n, p, _d, f);
        ll Kj = factorialPrime(k, p, _d, f);
        ll NKj = factorialPrime(nk, p, _d, f);
        res = (res * (((Nj * getModuloInverse(Kj, mod)) % mod) * getModuloInverse(NKj, mod)) % mod ) % mod;
    }
    res *= sw;
    res = (res + mod) % mod;
    res = (res * fpow(p, e_0)) % mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    memset(cache, 0, sizeof(cache));

    cache[0][0] = 1;
    cache[1][1] = 1;
    cache[1][0] = 1;
    for (int i = 0; i <= 40; i++) {
        cache[i][i] = 1;
        cache[i][0] = 1;
    }
    for (int i = 2; i <= 39; i++) {
        for (int j = 1; j < i; j++) {
            cache[i][j] = cache[i - 1][j] + cache[i - 1][j - 1];
        }
    }

    while (t--) {
        cin >> N >> K;
        // 3^3, 11, 13, 37
        ll nCk11 = nCkPrime(N, K, 11);
        ll nCk13 = nCkPrime(N, K, 13);
        ll nCk37 = nCkPrime(N, K, 37);
        ll nCk27 = granvile(N, K, 3, 3);
        vector<ll> primes = { 27, 11, 13, 37 };
        vector<ll> X = { nCk27, nCk11, nCk13, nCk37 };
        // cout << nCk11 << " " << nCk13 << " " << nCk27 << " " << nCk37 << endl;
        ll res = CRT(X, primes);
        cout << res << "\n";
    }
    return 0;
}
