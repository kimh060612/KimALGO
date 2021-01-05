#include <iostream>
#include <vector>
#include <stdlib.h>
#include<string.h>
#define MAX 10001

using namespace std;

vector<pair<int, int>> Adj[MAX];
int check[MAX];
int MaxSumCost = 0;
int u, v;

void DFS(int s, int cost)
{
    if (MaxSumCost < cost)
    {
        MaxSumCost = cost;
        u = s;
    }
    check[s] = 1;
    for (int i = 0; i < Adj[s].size(); i++)
    {
        int next_node = Adj[s][i].first;
        int weight = Adj[s][i].second;
        if (!check[next_node])
        {
            DFS(next_node, weight + cost);
        }
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N -1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Adj[a].push_back(make_pair(b, w));
        Adj[b].push_back(make_pair(a, w));
    }    
    DFS(1, 0);    
    memset(check, 0, sizeof(check));

    DFS(u, 0);
    cout << MaxSumCost << endl;
    return 0;
}