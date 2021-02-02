#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int N, A[MAX][MAX];
int degree[MAX];

void Euler(int node)
{
    for (int i = 1; i <= N; i++)
    {
        while (A[node][i])
        {
            A[node][i] --;
            A[i][node] --;
            Euler(i);
        }
    }
    cout << node << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> A[i][j];
            degree[i] += A[i][j];
            degree[j] += A[i][j];
        }
    }

    bool canEuler = true;
    for (int i = 1; i <= N; i++)
    {
        degree[i] /= 2;
        if (degree[i] % 2 == 1)
        {
            canEuler = false;
            break;
        }
    }

    if (canEuler)
    {
        Euler(1);
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}