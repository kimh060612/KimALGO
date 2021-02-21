#include <iostream>
#include <queue>
#include <tuple>
#define MAX 2001

using namespace std;

int S, DP[MAX], Visit[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> S;

    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(1, 0, 0));
    Visit[1][0] = 1;

    int ans = 0;

    while (!Q.empty())
    {
        int now_imo = get<0>(Q.front());
        int now_clip = get<1>(Q.front());
        int t = get<2>(Q.front());
        Q.pop();

        if (now_imo == S)
        {
            ans = t;
            break;
        }

        if (now_imo > 0 && now_imo < MAX)
        {
            if (!Visit[now_imo][now_imo])
            {
                Visit[now_imo][now_imo] = 1;
                Q.push(make_tuple(now_imo, now_imo, t + 1));
            }
            if (!Visit[now_imo - 1][now_clip])
            {
                Visit[now_imo - 1][now_clip] = 1;
                Q.push(make_tuple(now_imo - 1, now_clip, t + 1));
            }
        }

        if (now_clip > 0 && now_imo + now_clip < MAX)
        {
            if(!Visit[now_imo + now_clip][now_clip])
            {
                Visit[now_imo + now_clip][now_clip] = 1;
                Q.push(make_tuple(now_imo + now_clip, now_clip, t + 1));
            }
        }
    }

    cout << ans << endl;
    return 0;
}