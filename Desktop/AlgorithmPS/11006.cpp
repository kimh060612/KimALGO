#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << b * 2 - a << " "  << a - b << endl;
    }
    return 0;
}