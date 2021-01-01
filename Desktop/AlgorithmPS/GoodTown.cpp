#include <iostream>
#include <vector>
#define MAX 10000
#define max(a, b) a > b ? a : b

using namespace std;

int N;
int numCitizen[MAX + 1];
int check[MAX + 1], DP[MAX + 1][2];
vector<int> adj[MAX + 1];

void DFS(int node)
{

    for (int i = 0; i < adj[node].size(); i++)
    {
        int nx = adj[node][i];
        if (check[nx])continue;
        check[nx] = 1;
        DFS(nx);
        DP[node][0] += DP[nx][1];
        DP[node][1] += max(DP[nx][0], DP[nx][1]);
    }
    DP[node][0] += numCitizen[node];
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> numCitizen[i];
    }
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    check[1] = 1;
    DFS(1);

    int answer = max(DP[1][0], DP[1][1]);

    cout << answer << endl;

    return 0;
}