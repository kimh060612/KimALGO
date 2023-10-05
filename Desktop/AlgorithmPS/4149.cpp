#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;
using ull = unsigned long long;
using il = __int128;

ull N;

il Abs(il x) { return x < 0 ? -x : x; }
ull gcd(ull a, ull b) { 
    if(a < b) swap(a, b);
    while(b != 0) {
        ull r = a%b;
        a = b;
        b = r;
    }
    return a;
}

ull fpow(il x, il n, il mod) {
    x %= mod;
    il ret = 1;
    while (n > 0) {
        if (n % 2 == 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return (ull)ret;
}

bool check(ull n, ull a) {
    if(a % n == 0) return true;
    ull k = n-1;
    while(1) {
        ull temp = fpow(a, k, n);
        if(temp == n-1) return true;
        if(k % 2 == 1) return (temp == 1 || temp == n-1);
        k /= 2;
    }
}

bool isPrime(ull n) {
    if(n == 2 || n == 3) return true;
    if(n%2 == 0) return false;

    ull a[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
    for(int i=0; i<12; i++){
        if(!check(n, a[i])) {
            return false;
            break;
        }
    }
    return true;
}

ull rho(il n) {
    if(n % 2 == 0) return 2;
    if(isPrime(n)) return n;

    il x = rand()%(n - 2) + 2, y = x, c = rand()%10 + 1, g = 1;
    while(g == 1) {
        x = (x * x % n + c) % n;
        y = (y * y % n + c) % n;
        y = (y * y % n + c) % n;
        g = gcd(Abs(x - y), n);
        if(g == n) return rho(n);
    }
    if(isPrime(g)) return g;
    else return rho(g);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    vector<ull> ret;
    while (N > 1) {
        ull d = rho(N);
        ret.push_back(d);
        N /= d;
    }
    sort(ret.begin(), ret.end());
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << "\n";
    }
    return 0;
}