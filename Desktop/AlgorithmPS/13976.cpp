#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
using ll = long long;
using mat = pair<pair<ll, ll>, pair<ll, ll>>;

ll N, ret;

mat multiply(mat a, mat b) {
    mat ret;
    ret.first.first = (a.first.first * b.first.first + a.first.second * b.second.first + MOD) % MOD;
    ret.first.second = (a.first.first * b.first.second + a.first.second * b.second.second + MOD) % MOD;
    ret.second.first = (a.second.first * b.first.first + a.second.second * b.second.first + MOD) % MOD;
    ret.second.second = (a.second.first * b.first.second + a.second.second * b.second.second + MOD) % MOD;
    return ret;
}

mat fpow(mat a, ll n) {
    mat ret = { { 1, 0 }, { 0, 1 } };
    while (n) {
        if (n % 2 == 1) ret = multiply(ret, a);
        a = multiply(a, a);
        n /= 2;
    }
    return ret;
}

int main() {
    cin >> N;
    if (N % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }
    mat coeff = { { 4, -1 }, { 1, 0 } };
    mat retMat = fpow(coeff, N / 2 - 1);
    ll ret = (3 * retMat.first.first + retMat.first.second) % MOD;
    cout << ret << "\n";
    return 0;
}