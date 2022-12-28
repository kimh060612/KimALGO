#include <iostream>

using namespace std;
typedef long long ll;

ll DP[40];

ll dyp(int n)
{
    if (n == 0) return 1;
    if (DP[n] != 0) return DP[n];
    ll sum = 0;
    for (int i = 0; i < n; i++)sum += dyp(i) * dyp(n - 1 - i);
    DP[n] = sum;
    return DP[n];
}

int main()
{
    int n;
    cin >> n;
    DP[0] = 1;
    cout << dyp(n) << endl;
    return 0;
}