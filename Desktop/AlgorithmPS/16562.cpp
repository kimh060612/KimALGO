#include <iostream>
#include <vector>

using namespace std;

int N, M, k;
vector<int> A[10001];
int cost[10001], parent[10001];
int cnt = 1;

int find(int x)
{
    if (parent[x] < 0) return x;
    else return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
    if (x == y) return;
    else {
        int x_ = find(x);
        int y_ = find(y);
        if (x_ == y_)return;
        else 
        {
            if (cost[x_] < cost[y_])parent[y_] = x_;
            else parent[x_] = y_;
        }
    }
}

int main()
{
    cin >> N >> M >> k;
    for (int i = 1; i <= N; i++)parent[i] = -1;
    for (int i = 1; i <= N; i++) cin >> cost[i];
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
        Union(a, b);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (parent[i] == -1)
        {
            ans += cost[i];
        }
    }

    if (ans > k)cout << "Oh no" << endl;
    else cout << ans << endl;
    return 0;
}