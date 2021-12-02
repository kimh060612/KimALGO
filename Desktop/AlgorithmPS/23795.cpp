#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    while (1)
    {
        int a;
        cin >> a;
        if (a == -1) break;
        sum += a;
    }
    cout << sum << endl;
    return 0;
}