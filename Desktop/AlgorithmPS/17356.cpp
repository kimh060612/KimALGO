#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    double M = (b - a) / (double)400;
    double res = 1. / (1 + pow(10, M));
    cout.precision(15);
    cout << fixed;
    cout << res << endl;
    return 0;
}