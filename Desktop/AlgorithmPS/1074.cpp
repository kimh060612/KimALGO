#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int N;
ll r, c, ans;

ll Zfunc(int n, ll k, int y, int x)
{
    if (n == 0) return k;
    ll delta = pow(2, n - 2);
    ll skip = pow(4, n - 1);
    if (x > c && y > r)
    {
        int x_ = x - delta;
        int y_ = y - delta;
        return Zfunc(n - 1, k, y_, x_);
    }
    else if (x > c && y <= r)
    {
        int x_ = x - delta;
        int y_ = y + delta;
        return Zfunc(n - 1, k + 2 * skip, y_, x_);
    }
    else if (x <= c && y > r)
    {
        int x_ = x + delta;
        int y_ = y - delta;
        return Zfunc(n - 1, k + 1 * skip, y_, x_);
    }
    else
    {
        int x_ = x + delta;
        int y_ = y + delta;
        return Zfunc(n - 1, k + 3 * skip, y_, x_);
    }
}

int main()
{
    cin >> N >> r >> c;
    ll x = 1 << (N - 1), y = 1 << (N - 1);
    ans = Zfunc(N, 0, x, y);

    cout << ans << endl;
    return 0;
}