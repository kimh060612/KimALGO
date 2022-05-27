#include <iostream>
#define MOD 45678

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 5, k = 7;
    for (int i = 2; i <= n; i++)
    {
        sum = (sum + k) % MOD;
        k = (k + 3) % MOD;
    }

    cout << sum << endl;

    return 0;
}