#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int N;
int node[100001], check[100001];
vector<pair<int, int>> V[100001];

void search(int x)
{
    queue<int> Q;
    Q.push(x);
    check[x] = 1;
    while (!Q.empty())
    {
        int y = Q.front();
        Q.pop();

        for (int i = 0; i < V[y].size(); i++)
        {
            int ny = V[y][i].first;
            int cost = V[y][i].second;
            if (!check[ny])
            {
                Q.push(ny);
                node[ny] = max(node[y] + cost, node[ny]);
                check[ny] = 1;
            }
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N - 1; i++)
    {
        int a;
        cin >> a;
        while (1)
        {
            int b, c;
            cin >> b;
            if (b == -1) break;
            cin >> c;
            V[a].push_back({b, c});
            V[b].push_back({a, c});
        }
    }

    memset(check, 0, sizeof(check));
    memset(node, 0, sizeof(node));
    search(1);
    int max_index = 0, max_val = 0;
    for (int i = 1; i <= N; i++)
    {
        if (max_val < node[i])
        {
            max_val = node[i];
            max_index = i;
        }
    }

    memset(check, 0, sizeof(check));
    memset(node, 0, sizeof(node));
    search(max_index);
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (ans < node[i])
        {
            ans = node[i];
        }
    }

    cout << ans << endl;

    return 0;
}