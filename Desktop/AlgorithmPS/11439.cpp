#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int isPrime[4000002];
int NPrime[4000002];
int N, K, M;
    
void Sieve() {
    for (int i = 2; i <= (int)sqrt(N) + 1; i++) {
        for (int k = 2; i * k <= N; k ++) {
            if (!isPrime[k * i]) continue;
            isPrime[k * i] = 0;
        }
    }
    isPrime[1] = 0;

    vector<int> primes(0);
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) 
            primes.push_back(i);
    }

    int tN, tNK;
    for (int i = N; i >= K + 1; i --) {
        if (isPrime[i]) {
            NPrime[i]++;
            continue;
        }
        int index = 0;
        tN = i;
        while (tN > 1) {
            int iter = primes[index];
            if (iter > tN) break;
            if (isPrime[tN]) {
                NPrime[tN] ++;
                break;
            }
            while (tN % iter == 0) {
                tN /= iter;
                NPrime[iter] ++;
            }
            index++;
        }
    }

    for (int i = N - K; i >= 2; i --) {
        if (isPrime[i]) {
            NPrime[i]--;
            continue;
        }
        int index = 0;
        tNK = i;
        while (tNK > 1) {
            int iter = primes[index];
            if (iter > tNK) break;
            if (isPrime[tNK]) {
                NPrime[tNK] --;
                break;
            }
            while (tNK % iter == 0) {
                tNK /= iter;
                NPrime[iter] --;
            }
            index++;
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
    return ret;
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
    
    for (int i = 2; i <= N; i++) {
        if (NPrime[i] == 0) continue;
        ans = (ans * fpow(i, NPrime[i])) % M;
    }

    cout << ans << endl;
    return 0;
}