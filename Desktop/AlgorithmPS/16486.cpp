#include <iostream>
#define PI 3.141592

using namespace std;

int main()
{
    int d1, d2;
    cin >> d1 >> d2;
    cout.precision(10);
    cout << fixed;
    cout << 2 * d1 + 2 * PI * d2 << endl;
    return 0;
}