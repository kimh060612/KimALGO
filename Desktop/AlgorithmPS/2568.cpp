#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>
#define MAX 500001

using namespace std;

int N;
vector<pair<int, int>> V;
vector<pair<int, int>> A;
int trace[MAX];
int visit[MAX];

int search(int x)
{
    int s = 0, e = A.size() - 1;
    int mid;
    while (s < e)
    {
        mid = (s + e) / 2;
        if (A[mid].second >= x) e = mid;
        else s = mid + 1; 
    }
    return e;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }

    sort(V.begin(), V.end());
    A.push_back(V[0]);
    trace[0] = 1;
    for (int i = 1; i < N; i++)
    {
        if (A.back().second < V[i].second)
        {
            A.push_back(V[i]);
            trace[i] = A.size();
        }
        else
        {
            int x = search(V[i].second);
            A[x] = V[i];
            trace[i] = x + 1;
        }
    }
    cout << N - A.size() << "\n";
    int k = A.size();
    for (int i = N - 1; i >= 0 && k; i--)
    {
        if (trace[i] == k)
        {
            visit[i] = 1;
            k --;
        }
    }

    for (int i = 0; i < N; i++) if (!visit[i]) cout << V[i].first << "\n";
    return 0;
}