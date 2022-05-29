#include <iostream>
#include <vector>

using namespace std;

int n, m, visited[2001];
vector<int> E[2001];

bool dfs(int x, int depth)
{
    if (depth >= 4) return true;
    visited[x] = 1;
    bool result = false;
    for (int i = 0; i < E[x].size(); i++)
    {
        int nx = E[x][i];
        if (!visited[nx]) result |= dfs(nx, depth + 1);
    }
    visited[x] = 0;
    return result;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    bool result = false;
    for (int i = 1; i <= n; i++)
    {
        result |= dfs(i, 0);
    }
    
    if (result) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}