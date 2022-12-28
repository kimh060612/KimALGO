#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long s;
    cin >> s;
    int n = (-1 + (int)sqrt(1 + 8 * s)) / 2;
    cout << n << endl;
    return 0;
}