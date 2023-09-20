#include <iostream>
#include <cmath>
#include <vector>
#define MAX 40000
#define LIM 20000000
#define MOD 1000000007

using namespace std;
using ll = long long;

int N, P, isPrime[MAX + 5], check[LIM + 5];
vector<int> prime;

void sieve() {
    fill(isPrime, isPrime + MAX + 3, 1);
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int x = 2; x <= MAX; x++) {
        if(!isPrime[x]) continue;
        for (int j = 2 * x; j <= MAX; j += x) {
            isPrime[j] = 0;
        }
    }

    for (int x = 2; x <= MAX; x++) {
        if (x >= P) break;
        if (isPrime[x]) prime.push_back(x);
    }
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

ll count(int x) {
    ll ret = x;
    int num = prime.size();
    for (int i = 1; i < (1 << num); i++) {
        int t = 1, cnt = 0, flag = false;
        for (int j = 0; j < num; j++) {
            if (!(i & (1 << j))) continue;
            if (lcm((ll)t, prime[j]) > x) {
                flag = true;
                break;
            }
            t = lcm((ll)t, prime[j]);
            cnt ++;
        }
        if (!flag) ret += ((x / t) * (cnt % 2 == 1 ? -1 : 1));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> P;

    if (P == 2) {
        if (N * P > 1e9) cout << 0 << "\n";
        else cout << N * P << "\n";
    } else if (P < 50) {
        sieve();
        ll s = 0, e = 1e9;
        while (s + 1 < e) {
            int mid = (s + e) / 2;
            if (count(mid) < N) s = mid;
            else e = mid;
        } 
        ll ret = (ll)e * P;
        if (ret > 1e9) cout << 0 << "\n";
        else cout << ret << "\n";
    } else {
        for (int x = 2; x < P && x <= LIM; x++) {
            if (check[x]) continue;
            for (int k = x; k <= LIM; k += x) check[k] = 1;
        }
        int cnt = 0, p = 0;
        for (int i = 1; i <= LIM && cnt < N; i ++) 
            if (!check[i]) {
                cnt ++;
                p = i;
            }
        ll ret = (ll)p * P;
        if (cnt < N || ret > 1e9) cout << 0 << "\n";
        else cout << ret << "\n";
    }

    return 0;
}