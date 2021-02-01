#include <iostream>

using namespace std;
typedef long long ll;

void sum(ll n)
{
    if (n < 0)return;
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
    for(int i = 0; i < 10; i++) cout << c[i] << " ";
    cout << endl;
}

int main()
{
    ll N;
    cin >> N;
    sum(N);
    return 0;
}