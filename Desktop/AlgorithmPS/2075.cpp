#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    priority_queue<ll> PQ;
    cin >> N;
    int ans;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            ll a;
            cin >> a;
            PQ.push((-1)*a);
        }
        if (i == 1)continue;
        for (int j = 1; j <= N; j++)
        {
            ans = PQ.top();
            PQ.pop();
        }
    }
    ans = PQ.top();
    ans *= -1;
    cout << ans << endl;
    return 0;
}