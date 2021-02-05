#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

vector<int> edge[MAX];
int N, check[MAX], path[MAX], order[MAX];
int PPath[MAX];

bool compare(const int &i, const int &j)
{
    return order[i] < order[j];
}

void BFS()
{
    queue<int> Q;
    Q.push(1);
    check[1] = 1;
    int index = 1;
    while (!Q.empty())
    {
        int X = Q.front();
        Q.pop();
        
        PPath[index] = X;
        index ++;

        for (int i = 0; i < edge[X].size(); i++)
        {
            int nx = edge[X][i];
            if (!check[nx])
            {
                check[nx] = 1;
                Q.push(nx);
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> path[i];
        order[path[i]] = i;
    }

    for (int i = 1; i <= N; i++)
    {
        sort(edge[i].begin(), edge[i].end(), compare);
    }

    BFS();

    bool ans = true;
    for (int i = 1; i <= N; i++)
    {
        if (PPath[i] != path[i])ans = false;
    }

    if (ans) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}