#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <queue>
#define MAX 101

using namespace std;

int A[MAX][MAX], B[MAX][MAX];
int visited[MAX][MAX];
int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int y, int x) { return (1 <= x && x <= M && 1 <= y && y <= N);}

void BFS()
{
    queue<pair<int, int>> Q;
    Q.push({1, 1});

    while (!Q.empty())
    {
        int Y = Q.front().first;
        int X = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = X + dx[i];
            int ny = Y + dy[i];

            if (InRange(ny, nx) && A[ny][nx] == 0)
            {
                A[ny][nx] = -1;
                Q.push({ny, nx});
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

    int cnt = 0;
    int ans = 0, prev_ans = 0;
    while (1)
    {
        ans = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                B[i][j] = A[i][j];
                if (B[i][j] == 1)ans++;
            }
        }
        
        if (ans == 0)break;
        prev_ans = ans;
        cnt ++;
        BFS();

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (A[i][j] == 1)
                {
                    int tmp = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = j + dx[k];
                        int ny = i + dy[k];
                        if (A[ny][nx] == -1)tmp++;
                    }
                    if (tmp != 0)
                    {
                        B[i][j] = 0;
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                A[i][j] = B[i][j];
            }
        }
    }

    cout << cnt << endl << prev_ans << endl;

    return 0;
}