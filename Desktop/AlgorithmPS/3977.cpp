#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;
using ll = long long;
using iip = pair<int, int>;

ll N, M;
vector<int> G[100005];
vector<int> rG[100005];
int visited[100005], SCC[100005], indegree[100005];
stack<int> S;

void dfs(int x) {
    visited[x] = 1;
    for (auto nx: G[x]) {
        if (!visited[nx]) dfs(nx);
    }
    S.push(x);
}

void rdfs(int x, int index) {
    SCC[x] = index;
    visited[x] = 1;
    for (auto nx: rG[x]) {
        if (!visited[nx]) rdfs(nx, index);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) G[i].clear();
        for (int i = 1; i <= N; i++) rG[i].clear();
        for (int i = 1; i <= M; i++) {
            int a, b;
            cin >> a >> b;
            G[a + 1].push_back(b + 1);
            rG[b + 1].push_back(a + 1);
        }
        memset(SCC, 0, sizeof(SCC));
        memset(visited, 0, sizeof(visited));
        memset(indegree, 0, sizeof(indegree));
        for (int i = 1; i <= N; i++) {
            if (!visited[i]) dfs(i);
        }
        memset(visited, 0, sizeof(visited));
        int num = 1;
        while (!S.empty()) {
            int node = S.top();
            S.pop();
            if (!visited[node]) {
                rdfs(node, num);
                num ++;
            }
        }
        
        for (int i = 1; i <= N; i++) {
            for (auto node: G[i]) {
                if (SCC[i] != SCC[node]) indegree[SCC[node]]++; 
            }
        }
        
        int index = 0, cnt = 0;
        for(int i = 1; i < num; i++){
            if(indegree[i] == 0){
                index = i;
                cnt ++;
            }
        }

        if(cnt > 1) {
            cout << "Confused\n";
        } else {
            for (int i = 1; i <= N; i++) {
                if (index == SCC[i]) cout << i - 1 << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}