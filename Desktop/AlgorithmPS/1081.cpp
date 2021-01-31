#include <iostream>

using namespace std;

typedef long long ll;
int Summation[11];

ll sum(ll n)
{
    if (n < 0)return 0;
    ll c[10] = {0,}, s = 1, sum = 0, t, r;
    while (n > 0)
    {
        t = n / (s * 10);
        r = n % (s * 10);
        for(int i = 0; i < 10; i++) c[i] += t*s; 
        for(int i = 1; i <= r / s; i++) c[i] += s;
        c[(r/s + 1)%10] += r % s;
        n -= 9*s;
        s *= 10;
    }
    for(int i = 0; i < 10; i++) sum += i * c[i];
    return sum; 
}

int main()
{
    ll L, U;
    ll ans;
    cin >> L >> U;

    cout << sum(U) - sum(L - 1) << endl;

    return 0;
}