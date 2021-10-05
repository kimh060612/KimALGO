#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum = 0, min = 987654321;
        for (int i = 1; i <= 7; i++)
        {
            int a;
            cin >> a;
            if (a % 2 == 0)
            {
                sum += a;
                min = a < min ? a : min;
            }
        }
        cout << sum << " " << min << endl;
    }
    return 0;
}