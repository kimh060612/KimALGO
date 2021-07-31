#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, v1, v2;
vector<pair<int, int>> E[801];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b, c});
        E[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    
    
    return 0;
}