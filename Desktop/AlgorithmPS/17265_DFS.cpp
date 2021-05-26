#include <iostream>
#include <queue>
#include <cmath>
#include <string.h>

using namespace std;

int N;
char A[6][6];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

bool inRange(int y, int x) { return ( 1 <= x && x <= N && 1 <= y && y <= N ); }

int ans_min = 100000000, ans_max = -100000000;

void search(int y, int x, int ans, char t)
{
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (inRange(ny, nx))
        {
            if ((ny + nx)%2 == 1) {
                search(ny, nx, ans, A[ny][nx]);
            }
            else {
                int check;
                if (t == '*') check = ans * (A[ny][nx] - '0');
                else if (t == '+')check = ans + (A[ny][nx] - '0');
                else if (t == '-')check = ans - (A[ny][nx] - '0');
                if (ny == N && nx == N)
                {
                    ans_max = max(ans_max, check);
                    ans_min = min(ans_min, check);
                    return;
                }
                search(ny, nx, check, A[ny][nx]);
            }
        }
    }
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

    search(1,1, A[1][1] - '0', A[1][1]);

    cout << ans_max << " " << ans_min << endl;

    return 0;
}