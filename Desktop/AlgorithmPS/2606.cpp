#include <iostream>
#include <queue>

using namespace std;

int N, M, A[101][101];
int check[101];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        A[a][b] = 1;
        A[b][a] = 1;
    }

    queue<int> Q;
    Q.push(1);
    check[1] = 1;
    while (!Q.empty())
    {
        int X = Q.front();
        Q.pop();
        for (int i = 1; i <= N; i++)
        {
            int next = A[X][i];
            if (next && !check[i])
            {
                check[i] = 1;
                Q.push(i);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (check[i])ans ++;
    }
    cout << ans - 1 << endl;
    return 0;   
}