#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int idx = 1, sum = 0;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (a <= idx && idx <= b) sum += i;
            idx ++;
        }
    }
    cout << sum << endl;
    return 0;
}