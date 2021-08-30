#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    int e, f, g, h;
    cin >> a >> b >> c >> d;
    cin >> e >> f >> g >> h;
    int sumS = a + b + c + d;
    int sumT = e + f + g + h;
    cout << (sumS >= sumT ? sumS : sumT) << endl;
    return 0;
}