#include <iostream>

using namespace std;

int A[10];

bool as, ds, mix;

int main()
{
    as = true;
    ds = true;
    for (int i = 1; i <= 8; i++)
    {
        cin >> A[i];
    }

    for (int i = 1; i <= 7; i++)
    {
        if (A[i + 1] != A[i] + 1)as = false;
        if (A[i + 1] != A[i] - 1)ds = false;
    }

    if (as)
    {
        cout << "ascending" << endl;
    }
    if (ds) {
        cout << "descending" << endl;
    }
    if (!as && !ds) 
    {
        cout << "mixed" << endl;
    }
    return 0;
}