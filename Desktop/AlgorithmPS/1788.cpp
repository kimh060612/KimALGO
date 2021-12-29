#include <iostream>
#include <math.h>
#define MOD 1000000000

using namespace std;

int DP[1000001];

int main()
{
    int n;
    cin >> n;
    DP[1] = 1;
    for (int i = 2; i <= abs(n); i++) DP[i] = (DP[i - 1] + DP[i - 2]) % MOD;
    if (n < 0) {
        if ((-1 * n)%2 == 0) {
            cout << -1 << endl;
            cout << DP[(-1) * n] << endl;
        }
        else {
            cout << 1 << endl;
            cout << DP[(-1) * n] << endl;
        }
    }
    else if (n > 0) {
        cout << 1 << endl;
        cout << DP[n] << endl;
    }
    else {
        cout << 0 << endl;
        cout << 0 << endl;
    }
    return 0;
}