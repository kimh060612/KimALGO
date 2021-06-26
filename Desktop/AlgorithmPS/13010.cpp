#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 1000000000000000000

using namespace std;
typedef long long ll;


int numDivisor(ll n)
{
    int cnt = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt ++;
            if (i * i < n) cnt++;
        }
    }
    return cnt;
}

ll Hinverse(ll N)
{
    ll ans = INF * 9;

    for (int i = 2; i <= 30; i++)
    {
        ll s = 1, e = INF;
        ll k = -1;
        while (s <= e)
        {
            ll mid = (s + e) / 2;
            ll St = N;
            for (int j = 1; j <= i; j++)
            {
                St /= mid;
            }
            if (St == 1 && (ll)pow(mid, i) == N)
            {
                k = mid;
                break;
            }
            else if (St < 1 || (St == 1 && (ll)pow(mid, i) > N))e = mid - 1;
            else if (St > 1 || (St == 1 && (ll)pow(mid, i) < N))s = mid + 1;
        } 
        if (k != -1)
        {
            int num = numDivisor(k);
            if (num == i) ans = min(ans, k);
        }
    }
    return ans;
}

int main()
{
    ll N;
    cin >> N;

    ll ans = Hinverse(N);
    
    // for (int i = 2; i <= 1000; i++)
    // {
    //     int k = numDivisor(i);
    //     long long St = (long long)pow(i, k);
    //     if (St > 0 && St < pow(10, 18))
    //     {
    //         ll com = Hinverse(St);
    //         if (i != com) cout << i << " " << St << " " << com << endl;
    //     }
    // }
    cout << Hinverse(pow(105, 8)) << endl;
    if (ans == INF * 9) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
