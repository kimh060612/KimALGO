#include <iostream>

using namespace std;

int main()
{
    long long N1, N2, N3;
    int n;
    cin >> n;

    N1 = 0;
    N2 = 1;
    for (int i = 2; i <= n; i++)
    {
        N3 = N1 + N2;
        N1 = N2;
        N2 = N3;
    }

    if(n > 2)cout << N3 << endl;
    else if (n == 2 || n == 1)cout << 1 << endl;
    else if (n == 0)cout << 0 << endl;
    return 0;
}