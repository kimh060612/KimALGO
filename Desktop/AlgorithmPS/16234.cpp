#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

int N, L, R;
int A[51][51], check[51][51], Tmp[51][51];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int num;

bool inRange(int y, int x) {return (1 <= x && x <= N && 1 <= y && y <= N);}

void BFS(int y_, int x_)
{
    queue<pair<int, int>> Q;
    vector<pair<pair<int, int>, int>> V;
    Q.push(make_pair(y_, x_));
    V.push_back(make_pair(make_pair(y_,x_),A[y_][x_]));
    check[y_][x_] = 1;
    while (!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int Val = abs(A[y][x] - A[ny][nx]);
            if (!check[ny][nx] && Val >= L && Val <= R && inRange(ny, nx))
            {
                V.push_back(make_pair(make_pair(ny,nx),A[ny][nx]));
                Q.push(make_pair(ny, nx));
                check[ny][nx] = 1;
            }
        }
    }

    int mean = 0;
    for (int i = 0; i < V.size(); i++)
    {
        mean += V[i].second;
    }
    mean /= V.size();

    for (int i = 0; i < V.size(); i++)
    {
        int y = V[i].first.first;
        int x = V[i].first.second;
        A[y][x] = mean;
    }
    num = V.size();
}

int main()
{
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            Tmp[i][j] = A[i][j];
        }
    }
    int ans = 0;
    while (1)
    {
        memset(check, 0, sizeof(check));
        bool found = false;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (check[i][j])continue;
                num = 1;
                BFS(i,j);
                if (num >= 2)found = true;
            }
        }
        if (found)ans++;
        else break;
    }
    
    cout << ans << endl;

    return 0;
}