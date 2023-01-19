#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

int V, Q, K;
vector<int> G[1001];
vector<int> T[1001];
int Cost[1001][5];
int tDP[1001][20][5];
int check[1001]; // tDP의 업데이트가 끝난 Node.

void search(int depth, int ncolor, int nowCost, int parent, int pcolor, int factor) {
    if (T[parent].size() == depth) {
        tDP[parent][nowCost % K][pcolor] = (tDP[parent][nowCost % K][pcolor] + factor) % Q;
        return;
    }

    int next = T[parent][depth]; // parent의 자식들중 나머지가 k인 가능성을 쫒아서 간다.
    for (int i = 1; i <= 3; i++) {
        if (pcolor == 2 && i == 2) continue;
        if (pcolor == 3 && i != 2) continue;
        for (int k = 0; k < K; k++) {
            if (tDP[next][k][i] != 0) {
                search(depth + 1, i, (nowCost + k) % K, parent, pcolor, factor * tDP[next][k][i]);
            }
        }
    }
}

void dfs(int now, int ncolor) {
    if (T[now].size() == 0) {
        int m = Cost[now][ncolor] % K;
        tDP[now][m][ncolor] = 1;
        return;
    }

    for (int i = 0; i < T[now].size(); i++) {
        int next = T[now][i];
        if (check[next]) continue;
        for (int j = 1; j <= 3; j++) {
            if (ncolor == 2 && j == 2) continue;
            if (ncolor == 3 && j != 2) continue;
            dfs(next, j);
        }
        check[next] = 1; // 모든 색에 대해서 탐색이 끝나고 나면, 위의 노드에서 다시 탐색할 필요가 없음.
    }

    if (check[now]) return;
    for (int i = 1; i <= 3; i++) {  
        if (ncolor == 2 && i == 2) continue;
        if (ncolor == 3 && i != 2) continue;
        int next = T[now][0];
        for (int k = 0; k < K; k++){
            if (tDP[next][k][i] != 0) {
                int nextCost = (Cost[now][ncolor] + k) % K;
                search(1, i, nextCost, now, ncolor, tDP[next][k][i]);
            }
        }
    }

    // cout << "R: ";
    // for (int k = 0; k < K; k++) {
    //     cout << tDP[now][k][1] << " ";
    // }
    // cout << endl;
    // cout << "G: ";
    // for (int k = 0; k < K; k++) {
    //     cout << tDP[now][k][2] << " ";
    // }
    // cout << endl;
    // cout << "B: ";
    // for (int k = 0; k < K; k++) {
    //     cout << tDP[now][k][3] << " ";
    // }
    // cout << endl;
    // getchar();
}

void makeTree(int now, int parent) {
    for (int i = 0; i < G[now].size(); i++) {
        int next = G[now][i];
        if (next == parent) continue;
        T[now].push_back(next);
        makeTree(next, now);
    }
}

int main()
{
    fin >> V >> Q >> K;
    for (int i = 1; i < V; i++) {
        int a, b;
        fin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= V; i++) {
        fin >> Cost[i][1] >> Cost[i][2] >> Cost[i][3];
    }
    makeTree(1, 0);
        
    for (int i = 1; i <= 3; i++)
        dfs(1, i);

    vector<int> Test = { 1, 2, 5, 3, 4, 6, 7 };
    for (int t : Test) {
        cout << t << endl;
        cout << "R: ";
        for (int k = 0; k < K; k++) {
            cout << tDP[t][k][1] << " ";
        }
        cout << endl;
        cout << "G: ";
        for (int k = 0; k < K; k++) {
            cout << tDP[t][k][2] << " ";
        }
        cout << endl;
        cout << "B: ";
        for (int k = 0; k < K; k++) {
            cout << tDP[t][k][3] << " ";
        }
        cout << endl << endl;
        getchar();
    }

    int ans = 0;
    for (int i = 1; i <= 3; i++)
        ans = (ans + tDP[1][0][i]) % Q;

    cout << ans << "\n";

    return 0;
}