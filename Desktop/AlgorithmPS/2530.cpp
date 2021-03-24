#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    for (int i = 1; i <= 4; i++)
    {
        int a;
        cin >> a;
        sum += a;
    }
    cout << sum / 60 << endl << sum % 60 << endl;
    return 0;
}