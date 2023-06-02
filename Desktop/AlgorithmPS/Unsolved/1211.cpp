#include <iostream>
#define MAX 1e18 + 1

using namespace std;
using ll = long long;

ll selfProduct(ll n) { // O(lg N)
    ll res = 1, tmp = n;
    while (tmp) {
        if (res == 0) return 0;
        res *= (tmp % 10);
        tmp /= 10;
    }
    return res * n;
}

int main()
{
    ll lim;
    ll index = 0, k;
    cin >> lim;
    for (int i = 1; i <= lim; i++) {
        k = selfProduct(i);
        index = i;
        if (k > MAX) break;
    }
    cout << index << " " << k << endl;
    return 0;
}