#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        int a, b, c;
        cin >> a >> b;
        if (a == b && b == 0) break;
        cout << 2 * a - b << endl;
    }
    return 0;
}