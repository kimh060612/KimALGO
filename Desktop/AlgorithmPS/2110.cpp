#include <iostream>

using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a%b) : a;
}

int main()
{
    ll N, M;
    cin >> N >> M;
    cout << N * M / gcd(N, M) << endl;
    return 0;
}