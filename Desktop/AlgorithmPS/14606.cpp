#include <iostream>

using namespace std;

int DP[11];

int dyp(int n)
{
    if (n == 1) return 0;
    int &ret = DP[n];
    if (ret != 0) return DP[n];
    int m = -1;
    for (int i = 1; i < n; i++) m = max(m, i * (n - i) + dyp(i) + dyp(n - i));
    DP[n] = m;
    return m;
}

int main()
{
    int n;
    cin >> n;
    
    cout << dyp(n) << endl;
    return 0;
}