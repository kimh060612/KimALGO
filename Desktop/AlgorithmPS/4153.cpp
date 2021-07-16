#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 || b == 0 || c == 0) break;
        int k = max(max(a, b), c);
        if ((k*k == a*a + b*b) || (k*k == a*a + c*c) || (k*k == c*c + b*b)) cout << "right" << "\n";
        else cout << "wrong" << "\n";
    }
    return 0;
}