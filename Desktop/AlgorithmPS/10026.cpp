#include <iostream>
#include <queue>

using namespace std;

int N;
int A[101][101], check[101][101], B[101][101];
int check_C[101][101];
int ans_NC, ans_C;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool InRange(int y, int x) {return (1 <= x && x <= N && 1 <= y && y <= N);}

void BFS(int y, int x)
{
    queue<pair<int, int>> Q;
    int K = A[y][x];
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
            if (InRange(ny, nx) && A[ny][nx] == K && !check[ny][nx])
            {
                check[ny][nx] = 1;
                Q.push(make_pair(ny, nx));
            }
        }
    }
}

void BFS_C(int y, int x)
{
    queue<pair<int, int>> Q;
    int K = B[y][x];
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
            if (InRange(ny, nx) && B[ny][nx] == K && !check_C[ny][nx])
            {
                check_C[ny][nx] = 1;
                Q.push(make_pair(ny, nx));
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        char tmp[101];
        cin >> tmp;
        for (int j = 0; j < N; j++)
        {
            if(tmp[j] == 'R')A[i][j + 1] = 1;
            else if (tmp[j] == 'G')A[i][j + 1] = 2;
            else if (tmp[j] == 'B')A[i][j + 1] = 3;
            if(tmp[j] == 'R' || tmp[j] == 'G')B[i][j + 1] = 1;
            else if (tmp[j] == 'B')B[i][j + 1] = 2;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!check[i][j])
            {
                ans_NC++;
                check[i][j] = 1;
                BFS(i,j);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!check_C[i][j])
            {
                ans_C++;
                check_C[i][j] = 1;
                BFS_C(i,j);
            }
        }
    }

    cout << ans_NC << " " << ans_C << endl;

    return 0;
}