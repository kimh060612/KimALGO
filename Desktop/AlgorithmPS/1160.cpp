#include <iostream>

using namespace std;
typedef unsigned long long ll;
typedef pair<pair<ll, ll>, pair<ll, ll>> matrix;
ll m, a, c, x0, n, g;

ll mulmod(ll x, ll y) {
    x = x % m;
    y = y % m;
    ll tmp = x;
    ll res = 0;
    while (y) {
        if (y % 2 != 0) res = (res + tmp) % m;
        tmp = (2 * tmp) % m;
        y /= 2;
    }
    return res % m;
}

matrix matmul2x2(matrix a, matrix b){
    matrix res;
    res.first.first = (mulmod(a.first.first, b.first.first) + mulmod(a.first.second, b.second.first)) % m;
    res.first.second = (mulmod(a.first.first, b.first.second) + mulmod(a.first.second, b.second.second)) % m;
    res.second.first = (mulmod(a.second.first, b.first.first) + mulmod(a.second.second, b.second.first)) % m;
    res.second.second = (mulmod(a.second.first, b.first.second) + mulmod(a.second.second, b.second.second)) % m;
    return res;
}

ll solve() {
    matrix A = { { a % m, 0 }, { c % m, 1 } };
    matrix res = { { 1, 0 }, { 0, 1 } };
    while (n) {
        if (n % 2 == 1) res = matmul2x2(res, A);
        A = matmul2x2(A, A);
        n /= 2;
    }
    matrix init = { { x0 % m, 1 }, { 0, 0 } };
    matrix k = matmul2x2(init, res);
    return k.first.first % g;
}

int main()
{
    scanf("%lld %lld %lld %lld %lld %lld", &m, &a, &c, &x0, &n, &g);
    printf("%lld\n", solve());
    return 0;
}