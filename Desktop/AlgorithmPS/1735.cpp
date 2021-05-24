#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int a1, b1;
    int a2, b2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;

    int k = a1 * b2 + a2 * b1;
    int g = b1 * b2;
    int GCD = gcd(k ,g);

    cout << k / GCD << " " << g / GCD << endl;

    return 0;
}