#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

int R, C;
int Map[MAX][MAX];
queue<pair<int, int>> Fire;
queue<pair<pair<int, int>, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int y, int x) {return (1 <= x && x <= C && 1 <= y && y <= R);}

void BFS4Fire()
{
    int N = Fire.size();
    for (int i = 0; i < N; i++)
    {
        int X = Fire.front().second;
        int Y = Fire.front().first;
        Fire.pop();
        for (int j = 0; j < 4; j++)
        {
            int nx = X + dx[j];
            int ny = Y + dy[j];
            if (Map[ny][nx] == 1 && InRange(ny, nx))
            {
                Map[ny][nx] = 2;
                Fire.push({ny, nx});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        char t[MAX];
        cin >> t;
        for (int j = 0; j < C; j++)
        {
            if (t[j] == '#')Map[i][j + 1] = 0;
            else if (t[j] == '.')Map[i][j + 1] = 1;
            else if (t[j] == 'J')
            {
                Map[i][j + 1] = 3; 
                Q.push({{i, j + 1}, 1});
            }
            else if (t[j] == 'F')
            {
                Map[i][j + 1] = 2;
                Fire.push({i, j + 1});
            }
        }
    }
    
    while (1)
    {
        BFS4Fire();

        int K = Q.size();
        for (int k = 0; k < K; k++)
        {
            int X = Q.front().first.second;
            int Y = Q.front().first.first;
            int cnt = Q.front().second;
            Q.pop();

            if (X == C || Y == R || X == 1 || Y == 1)
            {
                cout << cnt << endl;
                return 0;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = X + dx[i];
                int ny = Y + dy[i];
                if (Map[ny][nx] == 1 && InRange(ny, nx))
                {
                    Map[ny][nx] = 3;
                    Q.push({{ny, nx}, cnt + 1});
                }
            }
        }

        if (Q.empty())
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    return 0;
}