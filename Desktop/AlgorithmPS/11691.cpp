#include <iostream>
#include <cmath>
#include <vector>
#define M 1000000007
#define MAX 1000001

using namespace std;
using ll = unsigned long long;

ll N;
ll f[MAX + 5];
int mu[MAX + 5];

void init() {
    mu[1] = 1;
    for(int i = 1; i <= MAX; i++) {
        for(int j = 2 * i; j <= MAX; j += i) {
            mu[j] -= mu[i];
        }
    }

    for(ll i = 1; i <= MAX; i++) {
        for(ll j = i; j <= MAX; j += i) {
            f[j] = (f[j] + mu[i] * i + M) % M;
        }
    }
    for(ll i = 1; i <= MAX; i++) f[i] = (f[i] * i) % M;
}

ll prod(ll x) {
    return (x * (x + 1) / 2) % M;
}

ll fpow(ll x, ll n) {
    ll ret = 1;
    while (n) {
        if (n % 2 == 1) ret = (ret * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ret;
}

ll getLCMSum(ll n) {
    ll ret = 0;
    for (ll k = 1; k <= n; k++) {
        ret = (ret + (((prod(n / k) * prod(n / k)) % M) * f[k]) % M - k + M) % M;
    }
    return (ret * fpow(2, M - 2)) % M;
}

int main(void)
{
    unsigned long long n; 
    init();
    cin >> n;
    cout << getLCMSum(n) << "\n";
    return 0;
}