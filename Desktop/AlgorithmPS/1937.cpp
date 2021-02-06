#include <iostream>
#include <string.h>
#include <stdlib.h>
#define MAX 501

using namespace std;

int N;
int A[MAX][MAX], DP[MAX][MAX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int y,int x) {return (1 <= x && x <= N && 1 <= y && y <= N);}
int max(int a, int b) { return a > b ? a : b; }

int DFS(int y, int x)
{
    int &ret = DP[y][x];
    if (ret != -1)return ret;

    ret = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (InRange(ny, nx) && A[ny][nx] > A[y][x])
        {
            ret = max(ret, DFS(ny, nx) + 1); 
        }
    }

    return ret;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {   
            cin >> A[i][j];
        }
    }

    memset(DP, -1, sizeof(DP));
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {   
            ans = max(DFS(i,j), ans);
        }
    }

    cout << ans << endl;

    return 0;
}