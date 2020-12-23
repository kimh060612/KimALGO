#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> map[100001];
stack<int> S;
int check[100001];
int tsize[100001];
int level[100001];
int path[100001];
bool answer;

int dfs(int x, int depth)
{
    if (check[x])return 0;
    check[x] = 1;
    
    int size = 1;
    level[x] = depth;
    for (int i = 0; i < map[x].size(); i++)
    {
        int next = map[x][i];
        size += dfs(next, depth + 1);
    }
    return tsize[x] = size;
}

int main()
{
    
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    dfs(1, 0);

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        path[i] = p;
    }
    if (path[0] != 1)
    {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i < n; i++)
    {
        int x = path[i];
        if (tsize[x] == 1 || tsize[x] >= n)continue;
        int next = path[i + tsize[x]];
        if (level[next] > level[x])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    
    return 0;
}