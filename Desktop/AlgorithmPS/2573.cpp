#include <iostream>
#include <queue>
#include <string.h>
#include <stdlib.h>

using namespace std;

int A[301][301], check[301][301], Map[301][301];
int N, M;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool InRange(int y, int x) {return (1 <= x && x <= M && 1 <= y && y <= N);}

void BFS(int y, int x)
{
    queue<pair<int, int>> Q;
    check[y][x] = 1;
    Q.push(make_pair(y, x));
    while (!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (InRange(ny, nx) && !check[ny][nx] && A[ny][nx])
            {
                Q.push(make_pair(ny, nx));
                check[ny][nx] = 1;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> A[i][j];
        }
    }

    int ans = 0;
    while (1)
    {
        memset(check, 0, sizeof(check));
        memset(Map, 0, sizeof(Map));
        int count = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (A[i][j] != 0 && !check[i][j])
                {
                    count ++;
                    BFS(i,j);
                }
            }
        }
        if (count >= 2)break;
        if (count == 0) {ans = 0; break;}
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (A[i][j] != 0)
                {
                    int tmp = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = j + dx[k];
                        int ny = i + dy[k];
                        if (A[ny][nx] == 0)tmp ++;
                    }
                    Map[i][j] = A[i][j] - tmp;
                    if (Map[i][j] < 0)Map[i][j] = 0;
                }
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                A[i][j] = Map[i][j];
            }
        }

        ans ++;
    }

    cout << ans << endl;
    return 0;
}