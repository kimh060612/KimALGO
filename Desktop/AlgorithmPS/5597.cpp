#include <iostream>

using namespace std;

int A[40];

int main()
{
    for (int i = 1; i <= 28; i++)
    {
        int a;
        cin >> a;
        A[a] = 1; 
    }

    for (int i = 1; i <= 30; i++)
        if (!A[i]) cout << i << endl;
    return 0;
}