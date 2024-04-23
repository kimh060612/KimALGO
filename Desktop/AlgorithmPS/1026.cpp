#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> A, B;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void partition(int low, int high, int &pivot, vector<int> &S) {
    int p = S[low];
    int j = low;
	for(int i = low + 1; i <= high; i++)
		if (S[i] < p) {
			j++;
			swap(S[i], S[j]);
		}
    pivot = j;
    swap(S[pivot], S[low]);
}

void sort(int s, int e, vector<int> &S) {
    if (s >= e) return;
    int pivot;
    partition(s, e, pivot, S);
    sort(s, pivot - 1, S);
    sort(pivot + 1, e, S);
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    A.resize(N + 1);
    B.resize(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    sort(1, N, A);
    sort(1, N, B);

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        int j = N - i + 1;
        ret += (A[i] * B[j]);
    }
    cout << ret << "\n";
    return 0;
}