#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        int b = a / 25; // 4
        int c = (a - b * 25) / 10; // 2
        int d = (a - b * 25 - c * 10) / 5; //
        int e = (a - b * 25 - c * 10 - d * 5) / 1;
        cout << b << " " << c << " " << d << " " << e << endl;
    }
    return 0;
}