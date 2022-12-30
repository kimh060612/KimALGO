#include <iostream>

using namespace std;
int A[41];
int check[2000001];
int ans, n, s;

void tracking(int bit) {
    if (check[bit]) return;
    int sum = 0;
    check[bit] = 1;
    for (int i = 0; i < n; i++) {
        if (bit & (1 << i)) sum += A[i + 1]; 
    }
    if (sum == s) ans ++;
    for (int i = 0; i < n; i++) {
        if (!(bit & (1 << i))) {
            bit = bit | (1 << i);
            tracking(bit);
            bit &= ~(1 << i);
        }
    }
}

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) tracking((1 << i)); 

    cout << ans << endl;
    return 0;
}