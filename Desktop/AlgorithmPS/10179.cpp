#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        double k;
        cin >> k;
        cout << fixed;
        cout.precision(2);
        cout << "$" << k * 0.8 << endl;
    }
    return 0;
}