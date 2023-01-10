#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

ll isPrime[4000002];
ll NPrime[4000002];
vector<ll> primes(0);
ll N, K, M;
    
void Sieve() {
    for (int i = 2; i * i <= N; i++) {
        for (int k = 2; i * k <= N; k ++) {
            if (!isPrime[k * i]) continue;
            isPrime[k * i] = 0;
        }
    }
    isPrime[1] = 0;

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) 
            primes.push_back(i);
    }

    for (int i = 0; i < primes.size(); i++) {
        int p = primes[i];
        for (ll j = p; j <= N; j *= p) {
            NPrime[i] += (N / j) - (K / j) - ((N - K) / j);
        }
    }

}

ll fpow(ll a, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * a) % M;
        }
        a = (a * a) % M;
        n /= 2;
    }
    return ret % M;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> M;
    memset(isPrime, 1, sizeof(isPrime));
    Sieve();
    ll ans = 1;
    for (int i = 0; i < primes.size(); i++) {
        if (NPrime[i] == 0) continue;
        ans = (ans * fpow(primes[i], NPrime[i])) % M;
        if (ans == 0) break;
    }

    cout << ans << endl;
    return 0;
}