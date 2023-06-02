#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;
int N, n, L[51], Adj[51][51];
int eMatch[51], oMatch[51], visited[51];
int isPrime[3001];
vector<int> even, odd;

void Field() {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = 0;
    isPrime[1] = 0;

    for (int i = 2; i * i <= 3000; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j <= 3000; j += i) isPrime[j] = 0;
    }
}

bool dfs(int x) {
    if (visited[x]) return false;
    visited[x] = 1;
    for (int i = 0; i < n; i++) {
        if (Adj[x][i]) {
            if (oMatch[i] == -1 || dfs(oMatch[i])) {
                eMatch[x] = i;
                oMatch[i] = x;
                return true;
            }
        }
    }
    return false;
}

int biparititeMatching(int novisit) {
    int size = 0;
    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        visited[novisit] = 1;
        if (dfs(i)) size ++;
    }
    return size;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L[i];
        if (L[i] % 2 == 0) even.push_back(i);
        else odd.push_back(i);
    }
    if (even.size() != odd.size()) {
        cout << -1 << "\n";
        return 0;
    }
    Field();
    int s = L[1];
    n = N / 2;
    vector<int> P;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime[L[even[i]] + L[odd[j]]]) Adj[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        memset(eMatch, -1, sizeof(eMatch));
        memset(oMatch, -1, sizeof(oMatch));
        if (s == L[even[0]]) {
            if (Adj[0][i]) {
                eMatch[0] = i;
                oMatch[i] = 0;
                int res = biparititeMatching(0);
                if (res + 1 == n) P.push_back(L[odd[i]]);
            }
        } else if (s == L[odd[0]]){
            if (Adj[i][0]) {
                eMatch[i] = 0;
                oMatch[0] = i;
                int res = biparititeMatching(i);
                if (res + 1 == n) P.push_back(L[even[i]]);
            }
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