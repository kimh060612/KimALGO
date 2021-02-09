#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001

using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> E;
int parent[MAX];

// find parent 
int find(int x)
{
    if (parent[x] == x)return x;
    else return parent[x] = find(parent[x]);
}

void make_union(int y, int x)
{
    x = find(x);
    y = find(y);
    if (x == y)return;
    parent[y] = x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        E.push_back({c, {a, b}});
    }

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    sort(E.begin(), E.end());
    
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int s = E[i].second.first;
        int e = E[i].second.second;
        int w = E[i].first;

        if (find(s) != find(e))
        {
            make_union(s, e);
            ans += w;
        }
        else continue;
    }

    cout << ans << endl;
    return 0;
}