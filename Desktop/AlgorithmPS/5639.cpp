#include <iostream>
#include <algorithm>
using namespace std;
int A[10002];
 
void printNode(const int& left, const int& right) {
    if (left > right) return;
    
    int root = A[left];
    int last = right;
    while (A[last] > root) last--;
    printNode(left + 1, last);
    printNode(last + 1, right);
    cout << root << "\n";
}
 
int main() {
    int temp;
    int N = 0;
    while (scanf("%d", &temp) != -1) A[N++] = temp;
    printNode(0, N-1);
 
    return 0;
}
