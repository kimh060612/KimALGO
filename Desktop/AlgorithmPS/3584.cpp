#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, x, y;
int visited[10001];
vector<int> C[10001];

vector<int> bfs(int s)
{
    queue<int> Q;
    Q.push(s);
    visited[s] = 1;
    vector<int> res;

    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();

        res.push_back(x);

        for (int i = 0; i < C[x].size(); i++)
        {
            int nx = C[x][i];
            if (!visited[nx]) {
                visited[nx] = 1;
                Q.push(nx);
            }
        }
    }
    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) C[i].clear();
        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            C[b].push_back(a);
        }
        cin >> x >> y;

        memset(visited, 0, sizeof(visited));
        vector<int> start = bfs(x);
        memset(visited, 0, sizeof(visited));
        vector<int> end = bfs(y);

        int k = start.size() < end.size() ? start.size() : end.size();
        int i = 0, ans = start[0];
        while (i < k && start[i] == end[i]) 
        {
            ans = start[i];
            i ++;
        }
        cout << ans << endl;
    }

    return 0;
}