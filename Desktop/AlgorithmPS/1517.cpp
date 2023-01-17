#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ilp = pair<int, ll>;

ll N, A[500002], tmp[500002], res;

void dnq(int s, int e) {
    if (s == e) return;
    int mid = (s + e) / 2;
    dnq(s, mid);
    dnq(mid + 1, e);
    ll num = 0;
    int index = s, i = s, j = mid + 1;
    while (i <= mid && j <= e) {
        ll now;
        if (A[i] > A[j]) {
            now = A[j];
            num ++;
            j++;
        } else {
            now = A[i];
            res += num;
            i++;
        }
        tmp[index++] = now;
    }
    if (i > mid) {
        for (int a = j; a <= e; a++) tmp[index++] = A[a];
        num += (e - j + 1);
    } else {
        for (int a = i; a <= mid; a++){
            tmp[index++] = A[a];
            res += num;
        }
    }

    for (int a = s; a <= e; a++)
        A[a] = tmp[a];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) 
        cin >> A[i];

    dnq(1, N);
    cout << res << "\n";
    return 0;
}