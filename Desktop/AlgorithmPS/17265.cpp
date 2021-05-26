#include <iostream>
#include <queue>
#include <cmath>
#include <string.h>

using namespace std;

int N;
char A[6][6];
int DP_min[6][6], check[6][6], DP_max[6][6];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

bool inRange(int y, int x) { return ( 1 <= x && x <= 5 && 1 <= y && y <= 5 ); }
int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a > b ? a : b; }

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            DP_max[i][j] = -987654321;
            DP_min[i][j] = 987654321;
        }
    }

    queue<pair<int, int>> Q;
    Q.push({1, 1});
    DP_min[1][1] = A[1][1] - 48;

    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 2; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (inRange(next_y, next_x))
            {
                Q.push({ next_y, next_x });
                if ((next_x + next_y) % 2 == 1)
                {
                    DP_min[next_y][next_x] = min(DP_min[next_y][next_x], DP_min[y][x]);
                }
                else 
                {
                    if (A[y][x] == '*') DP_min[next_y][next_x] = min(DP_min[next_y][next_x], DP_min[y][x] * (A[next_y][next_x] - 48));
                    else if (A[y][x] == '+') DP_min[next_y][next_x] = min(DP_min[next_y][next_x], DP_min[y][x] + (A[next_y][next_x] - 48));
                    else if (A[y][x] == '-') DP_min[next_y][next_x] = min(DP_min[next_y][next_x], DP_min[y][x] - (A[next_y][next_x] - 48));
                }
            }
        }
    }

    memset(check, 0, sizeof(check));
    Q.push({1, 1});
    DP_max[1][1] = A[1][1] - 48;

    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 2; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (inRange(next_y, next_x))
            {
                check[next_y][next_x] = 1;
                Q.push({ next_y, next_x });
                if ((next_x + next_y) % 2 == 1) DP_max[next_y][next_x] = max(DP_max[next_y][next_x], DP_max[y][x]);
                else 
                {
                    if (A[y][x] == '*') DP_max[next_y][next_x] = max(DP_max[next_y][next_x], DP_max[y][x] * (A[next_y][next_x] - 48));
                    else if (A[y][x] == '+') DP_max[next_y][next_x] = max(DP_max[next_y][next_x], DP_max[y][x] + (A[next_y][next_x] - 48));
                    else if (A[y][x] == '-') DP_max[next_y][next_x] = max(DP_max[next_y][next_x], DP_max[y][x] - (A[next_y][next_x] - 48));
                }
            }
        }
    }

    cout << DP_max[N][N] << " " << DP_min[N][N] << endl;

    return 0;
}