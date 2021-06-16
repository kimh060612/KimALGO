#include <iostream>
#include <queue>

using namespace std;

int N, M;
int A[1001][1001], Time[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int y, int x) { return (1 <= y && y <= N) && (1 <= x && x <= M); }

int main()
{
    queue<pair<int, pair<int, int>>> Q;
    cin >> M >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> A[i][j];
            if (A[i][j] == 1) 
            {
                Time[i][j] = 0;
                Q.push({0, {i, j}});
            }
            else Time[i][j] = 987654321;
        }
    }

    while(!Q.empty())
    {
        int t = Q.front().first;
        int y = Q.front().second.first;
        int x = Q.front().second.second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (A[ny][nx] == 0 && InRange(ny, nx))
            {
                Q.push({t + 1, {ny, nx}});
                A[ny][nx] = 1;
                Time[ny][nx] = min(Time[ny][nx], t + 1);
            }
        }
    }

    int ans = 0;
    bool isValid = true;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (A[i][j] == 1)ans = max(Time[i][j], ans);
            if (A[i][j] == 0)isValid = false;
        }
    }

    if (!isValid) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}