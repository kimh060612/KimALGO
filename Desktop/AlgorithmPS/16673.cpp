#include <iostream>

using namespace std;

int main()
{
    int K, P, C;
    cin >> C >> K >> P;
    cout << K * C * (C + 1) / 2 + P * C * (C + 1) * (2 * C + 1) / 6 << endl;
    return 0;
}