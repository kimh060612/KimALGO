#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    for (int i = 1; i <= 5; i++)
    {
        int a;
        cin >> a;
        sum += a * a;
    }

    cout << sum % 10 << endl;
    return 0;
}