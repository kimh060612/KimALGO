#include <iostream>

using namespace std;

int main()
{
    int L, P;
    cin >> L >> P;
    for (int i = 1; i <= 5; i++)
    {
        int a;
        cin >> a;
        cout << a - L * P << endl;
    }
    return 0;
}