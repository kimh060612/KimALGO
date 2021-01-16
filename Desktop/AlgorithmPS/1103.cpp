#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int N, M;
int A[51][51], check[51][51];
int DP[51][51];
int maxDepth = -987654321;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool InRange(int y, int x) {return (1 <= x && x <= M && 1 <= y && y <= N);}
int Max(int a, int b) { return a > b ? a : b;}

int Depth(int y, int x)
{
    if (! (InRange(y, x) && A[y][x] > 0))return 0;
    if (check[y][x])
    {
        cout << -1 << endl;
        exit(0);
    }
    if (DP[y][x] != -1)return DP[y][x];
    check[y][x] = 1;
    DP[y][x] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i] * A[y][x];
        int ny = y + dy[i] * A[y][x];
        DP[y][x] = Max(DP[y][x], Depth(ny, nx) + 1);
    }
    check[y][x] = 0;
    return DP[y][x];
}

int main()
{
    memset(DP, -1, sizeof(DP));
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        char tmp[51];
        cin >> tmp;
        for (int j = 0; j < M; j++)
        {
            if (tmp[j] == 'H')A[i][j + 1] = -1;
            else A[i][j + 1] = tmp[j] - '0';
        }
    }

    int ans = Depth(1,1);

    cout << ans << endl;

    return 0;
}