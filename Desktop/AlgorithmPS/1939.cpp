#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stdlib.h>
#define MAX 100000

using namespace std;

int max(int a, int b) { return a > b ? a : b; }

int N, M;
int s,e;
int MAX_C = 0;
vector<pair<int, int>> A[MAX + 1];
bool visited[MAX + 1];

bool BFS(int Cost)
{
    queue<int> Q;
    Q.push(s);
    visited[s] = true;

    while (!Q.empty())
    {
        int X = Q.front();
        Q.pop();

        if (X == e) return true;

        for (int i = 0; i < A[X].size(); i++)
        {
            int nx = A[X][i].first;
            int nc = A[X][i].second;

            if (!visited[nx] && Cost <= nc)
            {
                visited[nx] = 1;
                Q.push(nx);
            }
        }

    }
    return false;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        A[a].push_back({b, c});
        A[b].push_back({a, c});
        MAX_C = max(MAX_C, c);
    }
    cin >> s >> e;

    int left = 0;
    int right = MAX_C;
    int ans = 0;
    while (left <= right)
    {
        int Mid = (left + right) / 2;
        for (int i = 1; i <= N; i++)
        {
            visited[i] = false;
        }
        if (BFS(Mid))
        {
            ans = max(ans, Mid);
            left = Mid + 1;
        }
        else
        {
            right = Mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}