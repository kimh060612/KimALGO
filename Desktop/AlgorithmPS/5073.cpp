#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;
        int max_ = max(a, max(b, c));
        int sum = a + b + c;
        if (2 * max_ < sum) {
            if (a == b && b == c) cout << "Equilateral" << endl;
            else if (a == b || b == c || c == a) cout << "Isosceles" << endl;
            else cout << "Scalene" << endl;
        }
        else cout << "Invalid" << endl;
    }
    return 0;
}