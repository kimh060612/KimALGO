#include <iostream>

using namespace std;

int main()
{
    int ham = 100000;
    for (int i = 1; i <= 3; i++)
    {
        int a;
        cin >> a;
        if (a <= ham)ham = a;
    }
    int drink = 100000;
    for (int i = 1; i <= 2; i++)
    {
        int a;
        cin >> a;
        if (a <= drink)drink = a;
    }

    cout << ham + drink - 50 << endl;
    return 0;
}