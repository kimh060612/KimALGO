#include <iostream>
#include <queue>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define MAX 300 + 1

using namespace std;

int MAP[MAX][MAX], check[MAX][MAX];
int N, M;
pair<int, int> Junan, Choco;

int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};

bool InRange(int  y, int x) { return (1 <= x && x <= M && 1 <= y && y <= N );}

bool BFS()
{
    queue<pair<int, int>> Q;
    Q.push(Junan);
    vector<pair<int, int>> V;
    while (!Q.empty())
    {
        int Y = Q.front().first;
        int X = Q.front().second;
        Q.pop();

        if (Y == Choco.first && X == Choco.second)
        {
            return true;
        }
        V.push_back({Y,X});
        for (int i = 0; i < 4; i++)
        {
            int nx = X + dx[i];
            int ny = Y + dy[i];
            if (InRange(ny, nx) && MAP[ny][nx] == 0 && !check[ny][nx])
            {
                check[ny][nx] = 1;
                Q.push({ny, nx});
            }
        }
    }

    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int nx = V[i].second + dx[j];
            int ny = V[i].first + dy[j];
            if (InRange(ny, nx))
                if (MAP[ny][nx] == 1)MAP[ny][nx] = 0;
        }
    }

    return false;
}

int main()
{
    cin >> N >> M;
    int x1, x2, y1, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    for (int i = 1; i <= N; i++)
    {
        char tmp[MAX];
        cin >> tmp;
        for (int j = 1; j <= M; j++)
        {
            if (tmp[j - 1] == '1')MAP[i][j] = 1;
            else if (tmp[j - 1] == '0')MAP[i][j] = 0;
            else if (tmp[j - 1] == '#')MAP[i][j] = 0;
            else if (tmp[j - 1] == '*')MAP[i][j] = 3;
        }
    }
    Junan.first = y1;
    Junan.second = x1;
    Choco.first = y2;
    Choco.second = x2;

    
    int time = 0;
    bool end = false;
    while (!end)
    {   
        memset(check, 0, sizeof(check));

        end = BFS();
        time ++;
    }

    cout << time << endl;

    return 0;
}