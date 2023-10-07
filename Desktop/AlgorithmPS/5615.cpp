#include <iostream>

using namespace std;
using ll = unsigned long long;

ll N, cnt;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll fpow(ll x, ll n, ll mod) {
    x %= mod;
    ll ret = 1;
    while (n) {
        if (n % 2 == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return ret;
}

bool check(ll n, ll a) {
    if(a % n == 0) return true;
    ll k = n - 1;
    while(1) {
        ll temp = fpow(a, k, n);
        if(temp == n - 1) return true;
        if(k % 2 == 1) return (temp == 1 || temp == n - 1);
        k /= 2;
    }
}

bool isPrime(ll n) {
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0) return false;

    ll a[] = { 2, 7, 61 };
    for(int i = 0; i < 3; i++){
        if(!check(n, a[i])) {
            return false;
            break;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    while (N--) {
        ll x;
        cin >> x;
        if (isPrime(2 * x + 1)) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}