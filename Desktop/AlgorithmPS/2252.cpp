#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

int N, M;
vector<int> edge[MAX];
int edge_num[MAX];
int sorted[MAX];
queue<int> Q;

void TopologicalSort()
{
    for (int i = 1; i <= N; i++)
    {
        int X = Q.front();
        Q.pop();

        sorted[i] = X;

        for (int j = 0; j < edge[X].size(); j++)
        {
            int next = edge[X][j];
            edge_num[next] -= 1;
            if (edge_num[next] == 0) Q.push(next);
        }
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge_num[b] += 1;
    }

    for (int i = 1; i <= N; i++)
    {
        if (edge_num[i] == 0)Q.push(i);
    }

    TopologicalSort();

    for (int i = 1; i <= N; i++)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;
    return 0;
}