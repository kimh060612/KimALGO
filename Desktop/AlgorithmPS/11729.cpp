#include <iostream>

using namespace std;

int N;

void hanoi(int s, int e, int tmp, int n)
{
    if (n == 1) cout << s << " " << e << "\n";
    else {
        hanoi(s, tmp, e, n - 1);
        cout << s << " " << e << "\n";
        hanoi(tmp, e, s, n - 1);
    }
}

int main()
{
    cin >> N;
    int ans = 1;
    cout << (1 << N) - 1 << "\n";
    hanoi(1, 3, 2, N);
    return 0;
}