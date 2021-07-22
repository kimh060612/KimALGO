#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    for (int i = -1000; i <= 1000; i++)
    {
        for (int j = -1000; j <= 1000; j++)
        {
            if (((a * i + b * j) == c) && ((d * i + e * j) == f))
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}