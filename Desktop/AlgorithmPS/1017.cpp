#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
int N, L[51], Adj[51][51];
int isPrime[3001], matched[51];

void Field() {
    for (int i = 2; i * i <= 3000; i++) {
        if (isPrime[i]) continue;
        for (int j = 2 * i; j <= 3000; j += i) isPrime[j] = 1;
    }
}

bool dfs(int x) {
    if (matched[x]) return false;
    for (int i = 1; i <= N; i++) {
        if (Adj[x][i]) {
            if (!matched[i] || dfs(matched[i])) {
                matched[i] = x;
                matched[x] = i;
                return true;
            }
        }
    }
    return false;
}

int bipartiteMatch() {
    int size = 0;
    for (int i = 2; i <= N; i++) {
        if (dfs(i)) ++size;
    }
    return size;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> L[i];
    Field();
    int s = L[1];
    vector<int> P;

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (i == j) continue;
            if (isPrime[L[i] + L[j]]) Adj[i][j] = 1;
        }
    }

    for (int j = 2; j <= N; j++) {
        if (Adj[1][j]) {
            memset(matched, 0, sizeof(matched));
            matched[1] = j;
            matched[j] = 1;
            int res = bipartiteMatch();
            cout << res << "\n";
            if (res == N / 2) P.push_back(L[j]);
        }
    }

    sort(P.begin(), P.end());
    if (P.size() == 0) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < P.size(); i++) cout << P[i] << " ";
    cout << "\n";
    return 0;
}