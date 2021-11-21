#include <iostream>
#include <string>

using namespace std;

int main()
{
    unsigned long long a, b;
    string c;
    cin >> a >> b >> c;
    int k = c[c.length() - 1] - '0';
    unsigned long long ans = a ^ b;
    if (k % 2 == 0) cout << a << endl;
    else cout << ans << endl;
    return 0;
}