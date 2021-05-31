#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
#define MAX 2e9

using namespace std;
typedef long long ll;

ll K;

ll num_square(ll M)
{
    ll N = sqrt(M);
    vector<int> mu(N + 1, -1);
    vector<bool> isPrime(N + 1, true);
    vector<ll> S(N + 1, 0);
    vector<ll> pvec;
    mu[1] = 1;

    for (ll i = 2; i <= N; i++)
    {
        if (isPrime[i]) pvec.push_back(i);
        for (ll p : pvec) {
            if (i * p > N) break;
            isPrime[i*p] = false;
            if (i % p == 0) {
                mu[i*p] = 0;
                break;
            }
            mu[i*p] = mu[i] * mu[p];
        }
    }

    ll ans = 0;
    for (ll i = 2; i <= N; i++)
    {
        ans += mu[i] * (M / (i*i));
    }
    ans *= -1;

    return ans;
}

int main()
{
    cin >> K;
    ll s = 0, e = MAX;
    ll mid = (s + e) / 2;
    while (s + 1 < e)
    {
        mid = (s + e) / 2;
        ll k = num_square(mid);
        k = mid - k;
        if (k < K){
            s = mid;
        }
        else{
            e = mid;
        }
    }

    cout << e << endl;

    return 0;
}