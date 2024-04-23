#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N;
int A[1000004][3];
ll ret;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i][1] >> A[i][2];
    }

    int last = A[N][2];
    for (int i = N - 1; i >= 1; i--) {
        ret += ((ll)A[i][1] * (ll)A[i][2] * last);
    }

    cout << ret << "\n";
    return 0;
}