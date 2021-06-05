#include <iostream>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    cout << (x * y > 0 ? (x > 0 ? 1 : 3) : (x > 0 ? 4 : 2)) << endl;
    return 0;
}