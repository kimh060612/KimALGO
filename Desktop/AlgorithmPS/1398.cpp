#include <iostream>

using namespace std;
typedef long long ll;

int t;
int DP[101];

int main()
{
    int list[4] = {0, 1, 10, 25};
    for (int i = 1; i <= 100; i++) DP[i] = 987654321;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (i >= list[j]) DP[i] = min(DP[i], DP[i - list[j]] + 1);
        }
    }

    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        while (n > 0)
        {
            ans += DP[n % 100];
            n /= 100;
        }
        cout << ans << endl;
    }
    return 0;
}