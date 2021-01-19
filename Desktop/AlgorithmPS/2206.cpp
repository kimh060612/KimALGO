#include <iostream>
#include <queue>
#include <string>
#define MAX 1001

using namespace std;

int N, M;
bool A[MAX][MAX];
// 0: never visited
// 1: visited
// 2: can visited
int check[MAX][MAX][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++)
        {
            A[i][j] = tmp[j] - '0';
        }
    }
    queue<pair<pair<int, int>, int>> Q;
    // ((y, x), 뚫린 경로?)
    Q.push({{0, 0}, 1});
    check[0][0][1] = 1;
    int ans = 0;
    while (!Q.empty())
    {
        int y = Q.front().first.first;
        int x = Q.front().first.second;
        int block = Q.front().second;
        Q.pop();

        if (y == N - 1 && x == M - 1)
        {
            ans = check[y][x][block];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((0 <= nx && nx < M && 0 <= ny && ny < N))
            {
                if (A[ny][nx] == 1 && block == 1)
                {
                    check[ny][nx][block - 1] = check[y][x][block] + 1;
                    Q.push({{ny, nx}, block - 1});
                }
                else if (A[ny][nx] == 0 && check[ny][nx][block] == 0)
                {
                    check[ny][nx][block] = check[y][x][block] + 1;
                    Q.push({{ny, nx}, block});
                }
            }
        }
    }
    if (ans == 0)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}