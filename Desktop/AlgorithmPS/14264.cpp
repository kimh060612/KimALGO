#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a;
    cin >> a;
    cout.precision(20);
    cout << fixed ;
    cout << (1. / 4.) * sqrt(3) * a * a << endl;
    return 0;
}