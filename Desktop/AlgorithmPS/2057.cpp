#include <iostream>

using namespace std;
typedef long long ll;

ll A[21];

ll fac(ll n)
{
    if (n == 0)return 1;
    ll ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}

int main()
{
    ll N;
    cin >> N; // 20C10
    for (int i = 0; i <= 20; i++) A[i] = fac(i);

    bool ans = false;
    for (int i = 1; i <= (1 << 20); i++)
    {
        ll k = 0;
        for(int j = 0; j <= 20; j++)
        {
            if (i & (1 << j)) k += A[j];
        }
        if (k == N) ans = true;
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}