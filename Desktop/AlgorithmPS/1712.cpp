#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (B >= C)
    {
        cout << -1 << endl;
    }
    else 
    {
        cout << (int)(A/(C - B) + 1) << endl;
    }
    return 0;
}