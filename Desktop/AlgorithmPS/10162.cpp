#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    if (T % 10 != 0) cout << -1 << endl;
    else cout << T / (5 * 60) << " " << (T % (5 * 60)) / (60) << " " << (T % (5 * 60)) % 60 / 10 << endl;
    return 0;
}