#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ans = max(b - a, c - b);
    cout << ans - 1 << endl;
    return 0;
}