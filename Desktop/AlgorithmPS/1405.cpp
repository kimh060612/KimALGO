#include <iostream>
#include <iomanip>

using namespace std;

int N,total_path, non_simple;
bool visited[31][31];
double probabilty[4];
double answer = 0.;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void DFS(int n, int x, int y, double prob)
{
    if (n == 0)
    {
        answer += prob;
        return;
    }
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!visited[ny][nx])
        {
            DFS(n - 1, nx, ny, prob * probabilty[i]);
        }
    }
    visited[y][x] = 0;
}

int main()
{
    cin >> N;
    cin >> probabilty[0] >> probabilty[1] >> probabilty[2] >> probabilty[3];

    probabilty[0] *= 0.01;
    probabilty[1] *= 0.01;
    probabilty[2] *= 0.01;
    probabilty[3] *= 0.01;

    DFS(N, 15, 15, 1.);

    cout << fixed;
    cout << setprecision(10) << answer << endl;

    return 0;
}