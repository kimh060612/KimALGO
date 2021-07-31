#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, M, K;
int A[1001][1001], check[1001][1001][20];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool inRange(int y, int x) { return (1 <= x && x <= M) && (1 <= y && y <= N); }

int main()
{
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            A[i][j + 1] = s[j] - '0';
        }
    }

    queue<pair<pair<pair<pair<int, int>, int>, int>, int>> Q;
    Q.push({{{{1, 1}, 1}, K}, 1});
    check[1][1][K] = 1;
    int ans = -1;
    while (!Q.empty())
    {
        int y = Q.front().first.first.first.first;
        int x = Q.front().first.first.first.second;
        int DN = Q.front().first.first.second;
        int numK = Q.front().first.second;
        int Cnt = Q.front().second;
        Q.pop();
        bool block = false;

        if (y == N && x == M) 
        {
            ans = Cnt;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            int nd = DN == 1 ? 0 : 1;
            if (inRange(ny, nx)) {
                if (A[ny][nx] == 0 && !check[ny][nx][numK]) {
                    check[ny][nx][numK] = 1;
                    Q.push({{{{ny, nx}, nd}, numK}, Cnt + 1});
                }
                if (numK >= 1 && A[ny][nx] == 1 && !check[ny][nx][numK - 1]) {
                    if (DN == 1) {
                        check[ny][nx][numK - 1] = 1;
                        Q.push({{{{ny, nx}, nd}, numK - 1}, Cnt + 1});
                    }
                    else {
                        block = true;
                    }
                }
            }
        }
        if (block) {
            int nd = DN == 1 ? 0 : 1;
            Q.push({{{{y, x}, nd}, numK}, Cnt + 1});
        }
    }

    if (ans == -1) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}