#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int parent[100001], check[100001];
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
vector<pair<int, pair<int, int>>> A;

int find(int x)
{
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

bool Union(int x, int y)
{
    int u = find(x);
    int v = find(y);

    if (u == v)return false;
    else 
    {
        if (u < v)  parent[v] = u;
        else parent[u] = v;
        return true;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        X.push_back({a, i});
        Y.push_back({b, i});
        Z.push_back({c, i});
        parent[i] = i;
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    for (int i = 0; i < N - 1; i++)
    {
        A.push_back({X[i + 1].first - X[i].first, { X[i].second, X[i + 1].second }});
        A.push_back({Y[i + 1].first - Y[i].first, { Y[i].second, Y[i + 1].second }});
        A.push_back({Z[i + 1].first - Z[i].first, { Z[i].second, Z[i + 1].second }});
    }

    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        int x = A[i].second.first;
        int y = A[i].second.second;

        bool cycle = Union(x, y);

        if (cycle)ans += A[i].first;
    }

    cout << ans << endl;

    return 0;
}