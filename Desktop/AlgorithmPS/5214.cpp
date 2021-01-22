#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000 + 1

using namespace std;

int N, K, M;
vector<int> Edge[MAX + 1000];
int Cost[MAX + 1000];

int main()
{
    cin >> N >> K >> M;
    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int a;
            cin >> a;
            Edge[a].push_back(i + N);
            Edge[i + N].push_back(a);
        }
    }

    queue<int> Q;
    Q. push(1);
    int ans = -1;
    Cost[1] = 1;
    while (!Q.empty())
    {
        int X = Q.front();
        Q.pop();
        
        if (X == N)
        {
            ans = Cost[X];
            break;
        }

        for (int i = 0; i < Edge[X].size(); i++)
        {
            int nx = Edge[X][i];
            if (Cost[nx] == 0)
            {
                if (nx > N) Cost[nx] = Cost[X];
                else Cost[nx] = Cost[X] + 1;
                Q.push(nx);
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}