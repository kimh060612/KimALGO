#include <iostream>
#define PI 3.14159265358979

using namespace std;

int main()
{
    int r;
    cin >> r;
    cout << fixed;
    cout.precision(6);
    cout << PI * r * r << endl;
    cout << 2.0 * r * r << endl;
    return 0;
}