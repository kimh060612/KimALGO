#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout.precision(3);
    cout << fixed;
    int index = 1;
    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        cout << "Triangle #" << index << endl;
        if (a == -1) {
            if (b >= c) cout << "Impossible." << endl;
            else cout << "a = " << sqrt(c * c - b * b) << endl;
        } else if (b == -1) {
            if (a >= c) cout << "Impossible." << endl;
            else cout << "b = " << sqrt(c * c - a * a) << endl;
        } else {
            cout << "c = " << sqrt(a * a + b * b) << endl;
        }  
        index ++;
        cout << endl;
    }
    return 0;
}