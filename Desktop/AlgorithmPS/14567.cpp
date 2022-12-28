#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> E[1001];
int N[1001], ANS[1001];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        E[a].push_back(b);
        N[b]++;
    }

    queue<pair<int, int>> Q;
    for (int i = 1; i <= n; i++)
        if (N[i] == 0) 
            Q.push({i, 1}); 
    
    while (!Q.empty())
    {
        int x = Q.front().first;
        int t = Q.front().second;
        Q.pop();
        ANS[x] = t;
        for (int i = 0; i < E[x].size(); i++)
        {
            int nx = E[x][i];
            N[nx] --;
            if (N[nx] == 0) Q.push({nx, t + 1});
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ANS[i] << " ";
    cout << endl;

    return 0;
}