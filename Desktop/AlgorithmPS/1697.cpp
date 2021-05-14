#include <iostream>
#include <queue>

using namespace std;

int N, K;
int check[100001];
queue<pair<int, int>> Q;

bool InRange(int x) { return (0 <= x && x <= 100000); }

int main()
{
    cin >> N >> K;
    check[N] = 1;
    Q.push({N, 0});
    int ans = 987654321;
    while (!Q.empty())
    {
        int X = Q.front().first;
        int t = Q.front().second;
        Q.pop();

        if (X == K)ans = min(ans, t);

        int next[3] = {X - 1, X + 1, 2 * X};
        for (int i = 0; i < 3; i++)
        {
            int ne_pos = next[i];
            if (InRange(ne_pos) && !check[ne_pos])
            {
                check[ne_pos] = 1;
                Q.push({ne_pos, t + 1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}