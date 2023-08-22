#include <iostream>
#include <string.h>
#include <map>
#include <set>
#define MAX 300005

using namespace std;
using ll = long long;

ll C;
int N, A[300005];
map<int,int> M;

int max(int a, int b) { return a > b ? a : b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    set<int> S;

    S.insert(A[1]);
    M.insert({ A[1], 0 });
    S.insert(0);
    M.insert({ 0, 0 });
    S.insert(N + 1);
    M.insert({ N + 1, 0 });
    cout << 0 << "\n";
    for (int i = 2; i <= N; i++) {
        auto up = S.upper_bound(A[i]);
        auto down = up--;
        S.insert(A[i]); 
        int b = max(M.at(*up), M.at(*down)) + 1;
        M[A[i]] = b;  
        C += b; 
        cout << C << "\n";
    }
    return 0;
}