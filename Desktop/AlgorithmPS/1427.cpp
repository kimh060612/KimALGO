#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

char number[25];
int N;
vector<int> A;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void partition(int low, int high, int &pivot, vector<int> &S) {
    int p = S[low];
    int j = low;
    for (int i = low + 1; i <= high; i ++) {
        if (S[i] < p) {
            j ++;
            swap(S[i], S[j]);
        }
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
    cin >> number;
    N = strlen(number);
    A.resize(N + 1);
    for (int i = 0; i < N; i++) {
        A[i + 1] = number[i] - '0';
    }
    sort(1, N, A);
    for (int i = N; i >= 1; i--) {
        cout << A[i];
    }
    cout << "\n";

    return 0;
}