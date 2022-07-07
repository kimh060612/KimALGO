#include <iostream>

using namespace std;

int main()
{
    double a;
    cin >> a;
    cout.precision(2);
    cout << fixed;
    while (1) 
    {
        double b;
        cin >> b;
        if (b == 999) break;
        cout << b - a << endl;
        a = b;
    }
    return 0;
}