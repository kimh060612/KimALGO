#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, pair<int ,int>>> E;
int parent[10001];

int find(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
    int px = find(x);
    int py = find(y);

    if (px != py) parent[px] = py;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        E.push_back({c, {a, b}});
    }
    for (int i = 1; i <= N; i++) parent[i] = i;
    sort(E.begin(), E.end());

    int ans = 0;
    for (int i = 0; i < E.size(); i++)
    {   
        int x = E[i].second.first;
        int y = E[i].second.second;
        if (find(x) == find(y))continue;
        else {
            Union(x, y);
            ans += E[i].first;
        }
    }

    cout << ans << endl;
    return 0;
}