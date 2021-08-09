#include <iostream>
#include <cmath>
#include <iomanip>
#define e 10
#define MINIMUN e-10

using namespace std;

int A, B, C;

long double F(long double x)
{
    return (long double)(A * x + B * sin(x) - C);
}

long double dF(long double x)
{
    return (long double)(A + B * cos(x));
}

int sign(long double x)
{
    if (x > 0.) return 1;
    else if (x == 0.) return 0;
    else return -1;
}

int main()
{   
    cin >> A >> B >> C;
    long double a = (C - B) / (long double)A, b = (C + B) / (long double)A;
    long double x = a + (b - a) / 2, error, x2 = 0.;
    error = x - x2;
    int num = 100000;
    while (error > MINIMUN && num --)
    {
        x2 = x;
        x -= F(x) / dF(x);
        error = fabs(x - x2);
    }
    cout << fixed << setprecision(20);
    cout << x << endl;
    return 0;
}