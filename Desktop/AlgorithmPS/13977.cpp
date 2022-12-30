#include <iostream>
#include <algorithm>
#define MOD 1000000007

using namespace std;
using ll = long long;

ll fpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) {
            res *= a;
        }
        a *= a;
        b /= 2;
    }
    return res;
}

int main()
{
    int m, n, k;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> m;

    }
    return 0;
}