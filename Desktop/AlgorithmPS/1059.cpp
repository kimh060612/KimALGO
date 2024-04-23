#include <iostream>
#include <vector>

using namespace std;

int L, n, ret;
vector<int> S;

void merge(int low, int mid, int high, vector<int> &A) {
    int i = low, j = mid + 1;
    int k = 1, N = high - low + 1;
    vector<int> ret;
    ret.resize(N + 1);
    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            ret[k] = A[i];
            i ++;
        }
        else {
            ret[k] = A[j];
            j ++;
        }
        k ++;
    }
    while (i <= mid) {
        ret[k] = A[i];
        i ++; k ++;
    }
    while (j <= high) {
        ret[k] = A[j];
        j ++; k ++;
    }
    for (int l = 1, h = low; l <= N; l ++, h ++){
        A[h] = ret[l];
    }
}

void sort(int s, int e, vector<int> &A) {
    if (s >= e) return;
    int mid = (s + e) / 2;
    sort(s, mid, A);
    sort(mid + 1, e, A);
    merge(s, mid, e, A);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L;
    S.resize(L + 1);
    for (int i = 1; i <= L; i++){
        cin >> S[i];
    }
    cin >> n;
    sort(1, L, S);

    int index = 1;
    for (int i = 1; i <= L; i++) {
        if (S[i] > n) {
            index = i - 1;
            break;
        }
    }

    int ret = 0;
    for (int i = S[index] + 1; i <= S[index + 1] - 1; i++) {
        for (int j = i + 1; j <= S[index + 1] - 1; j++) {
            if (i <= n && n <= j) ret ++;
        }
    }

    cout << ret << "\n";
    return 0;
}