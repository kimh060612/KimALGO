#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
vector<int> G[1001];
vector<int> T[1001];
int parent[1001], Adj[1001][1001], check[1001];

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void merge(int u, int v) {
    u = getParent(u);
    v = getParent(v);

    if (u != v) {
        if (u < v) parent[v] = u;
        else parent[u] = v;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    while (1) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        G[a].push_back(b);
        G[b].push_back(a);
        Adj[a][b] = 1;
        Adj[b][a] = 1;
    }
    for (int i = 1; i <= N; i++) parent[i] = i;

    vector<int> v;
	for(int i = 1; i <= N; i++){
		v.clear();
		for(int j = 1; j <= N; j++){
			if(i == j) continue;
			if(!Adj[i][j]) v.push_back(j);
		}
		for(int j=1; j<v.size(); ++j){
			merge(v[j - 1], v[j]);
		}
	}

	for(int i = 1; i <= N; i++){
		check[getParent(i)]++;
	}

    v.clear();
	int cnt=0;
	for(int i = 1; i <= N; i++){
		if(check[i] == 1){
			v.push_back(i);
		}
		else if(check[i] > 1){
			cnt++;
		}
	}
	if(!v.empty()) cnt++;
	if(cnt > 2){
		cout << "-1\n";
		return 0;
	}

	for(int i = 1; i < v.size(); i++){
		merge(v[i - 1], v[i]);
	}
	vector<int> res1;
	vector<int> res2;
	for(int i = 1; i <= N; i++){
		if(getParent(i) == 1) res1.push_back(i);
		else res2.push_back(i);
	}
	for(int i = 0; i < res1.size(); i++){
		for(int j = 0; j < i; j++){
			if(!Adj[res1[i]][res1[j]]){
				cout << "-1\n";
				return 0;
			}
		}
	}
	for(int i = 0; i < res2.size(); i++){
		for(int j = 0; j < i; j++){
			if(!Adj[res2[i]][res2[j]]){
				cout << "-1\n";
				return 0;
			}
		}
	}

	cout << "1\n";
	sort(res1.begin(), res1.end());
	sort(res2.begin(), res2.end());
	for(auto it:res1) cout << it << " ";
	cout << "-1\n";
	for(auto it:res2) cout << it << " ";
	cout << "-1\n";
    return 0;
}