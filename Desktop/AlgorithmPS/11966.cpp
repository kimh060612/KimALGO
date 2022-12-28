#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    while (a > 0)
    {
        if (a % 2 != 0 && a != 1)
        {
            cout << 0 << endl;
            return 0;
        }
        a /= 2;
    }
    cout << 1 << endl;
    return 0;
}