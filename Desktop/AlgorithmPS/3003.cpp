#include <iostream>

using namespace std;

int main()
{
    int A[6] = { 1, 1, 2, 2, 2, 8 };
    for (int i = 0; i < 6; i++)
    {
        int a;
        cin >> a;
        cout << A[i] - a << endl;
    }
    return 0;
}