#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[1010][1010], id;
stack<pair<int, int>> v[1010];
vector<int> chk;

void dfs(int u){
    while(1){
        while(!v[u].empty() && chk[v[u].top().second]) v[u].pop(); // 이미 쓰여진 간선이면 pop
        if(v[u].empty()) break;

        auto [x, y] = v[u].top(); v[u].pop();
        chk[y] = 1, dfs(x); // y번 간선을 사용했음을 표시하고 알고리즘을 계속한다.
    }

    printf("%d ",u);
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);

    for(int i=1;i<=n;i++){
    	for(int j=i+1;j<=n;j++){
    		while(a[i][j]){
    			a[i][j]--, id++;
    			v[i].push({j, id}), v[j].push({i, id}); // 간선에 번호를 부여한다.
    		}
    	}
    }
    chk.resize(id + 1);

    for(int i=1;i<=n;i++) if(v[i].size() % 2) return !printf("-1");

    dfs(1);
}