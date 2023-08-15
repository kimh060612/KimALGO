#include <iostream>
#define MAX 500005
#define NMAX 1000005

using namespace std;
using ll = long long;

ll tree[MAX * 5];
int N, A[MAX], B[NMAX];

void update(int node, int s, int e, int pos) {
    if (pos < s || e < pos) return;
    tree[node] += 1;
    if (s == e) return;
    int mid = (s + e) / 2;
    update(node * 2, s, mid, pos);
    update(node * 2 + 1, mid + 1, e, pos);
}

ll sum(int node, int s, int e, int qs, int qe) {
    if (s > qe || e < qs) return 0;
    if (qs <= s && e <= qe) return tree[node];
    int mid = (s + e) / 2;
    return sum(node * 2, s, mid, qs, qe) + sum(node * 2 + 1, mid + 1, e, qs, qe);
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) {
        int val;
        cin >> val;
        B[val] = i;
    }

    ll ret = 0;
    for (int i = 1; i <= N; i++) {
        int arr = B[A[i]];
        ret += sum(1, 1, N, arr + 1, N);
        update(1, 1, N, arr);
    }   
    cout << ret << "\n";
    return 0;
}