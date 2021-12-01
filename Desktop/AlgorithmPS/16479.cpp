#include <iostream>

using namespace std;

int main()
{
    int k, d1, d2;
    cin >> k >> d1 >> d2;
    double a = ((d1 - d2) / 2.) * ((d1 - d2) / 2.);
    cout.precision(6);
    cout << fixed;
    cout << (double)k * k - a << endl;
}