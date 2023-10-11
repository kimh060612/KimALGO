#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
using ull = unsigned long long;
using il = __int128;

il Abs(il x) { return x < 0 ? -x : x; }
ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
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

bool MillerRabin(ull n, ull a) {
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
        if(!MillerRabin(n, a[i])) {
            return false;
            break;
        }
    }
    return true;
}

ull p_rho(il n) {
    if(n % 2 == 0) return 2;
    if(isPrime(n)) return n;

    il x = rand() % (n - 2) + 2, y = x, c = rand() % 10 + 1, g = 1;
    while(g == 1) {
        x = (x * x % n + c) % n;
        y = (y * y % n + c) % n;
        y = (y * y % n + c) % n;
        g = gcd(Abs(x - y), n);
        if(g == n) return p_rho(n);
    }
    if(isPrime(g)) return g;
    else return p_rho(g);
}

bool checkFour(il x) {
    while (x % 4 == 0) {
        x /= 4;
    }
    return x % 8 == 7;
}

bool checkThree(ull x, il n) {
    ull cnt = 0;
    while (n % x == 0) {
        cnt ++;
        n /= x;
    }
    return (x % 4 == 3 && cnt % 2 == 1);
}

bool checkOne(il n) {
    ull a = sqrt(n);
    if (a*a == n) return true;
    return false;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ull N, oN;
    cin >> N;
    if (checkFour(N)) {
        cout << "4\n";
        return 0;
    }
    if (checkOne(N)) {
        cout << "1\n";
        return 0;
    }
    oN = N;

    while (N > 1) {
        ull d = p_rho(N);
        if (checkThree(d, oN)) {
            cout << "3\n";
            return 0;
        } 
        N /= d;
    }
    cout << "2\n";
    return 0;
}