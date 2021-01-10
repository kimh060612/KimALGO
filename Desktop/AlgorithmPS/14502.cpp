#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int A[20][20];
int Tmp[20][20];
vector<pair<int, int>> virus;
int TotalArea = -1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool inRange(int y, int x) {return (1 <= x && x <= M && 1 <= y && y <= N);}

void CopyMap(int (*a)[20], int (*b)[20])
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

void BFS()
{
    int Lab[20][20];
    CopyMap(Lab, Tmp);
    queue<pair<int, int>> Q;
    for (int i = 0; i < virus.size(); i++)
    {
        Q.push(virus[i]);
    }   

    while (!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (Lab[ny][nx] == 0 && inRange(ny, nx))
            {
                Lab[ny][nx] = 2;
                Q.push(make_pair(ny, nx));
            }
        }
    }
    int tmp_ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (Lab[i][j] == 0)tmp_ans ++;
        }
    }
    if (tmp_ans > TotalArea)TotalArea = tmp_ans;
}

void Wall(int cnt)
{
    if (cnt == 3)
    {
        BFS();
        return;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if (Tmp[i][j] == 0)
                {
                    Tmp[i][j] = 1;
                    Wall(cnt + 1);
                    Tmp[i][j] = 0;
                }
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
            Tmp[i][j] = A[i][j];
            if (A[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= M; j++) 
        {
            if(A[i][j] == 0){
                CopyMap(Tmp,A);
                Tmp[i][j] =1;
                Wall(1);
                Tmp[i][j] = 0;
            }
        }
    }

    cout << TotalArea << endl;

    return 0;
}