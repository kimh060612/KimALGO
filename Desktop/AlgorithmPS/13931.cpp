#include <iostream>
#include <queue>
#include <stack>
#define MAX 100000

using namespace std;

int N, K;
int visitied[MAX + 1], DP[MAX + 1];

int main()
{
    cin >> N >> K;

    queue<int> Q;
    Q.push(N);
    visitied[N] = -1;
    while (!Q.empty())
    {
        int X = Q.front();
        Q.pop();
        if (X == K)break;
        int next[3] = {X + 1, X - 1, 2*X};
        for (int i = 0; i < 3; i++)
        {
            int nx = next[i];

            if (0 <= nx && nx <= MAX)
            {
                if (visitied[nx] == 0 && X != 0)
                {
                    visitied[nx] = X;
                    DP[nx] = DP[X] + 1;
                    Q.push(nx);
                }
                else if (visitied[nx] == 0 && X == 0)
                {
                    visitied[nx] = -2;
                    DP[nx] = DP[X] + 1;
                    Q.push(nx);
                }
            }
        }
    }
    stack<int> S;
    cout << DP[K] << endl;
    int x = K;
    S.push(x);
    while (1)
    {
        x = visitied[x];
        if (x == -1)break;
        if (x == -2) x = 0;
        S.push(x);
    }
    while(!S.empty())
    {
        cout << S.top() << " ";
        S.pop();
    }
    cout << endl;
    return 0;
}