#include <iostream>

using namespace std;

int F[51];

int main()
{
    int N;
    cin >> N;
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= 50; i++)
    {
        F[i] = F[i - 1] + F[i - 2];
    }

    cout << F[N] << endl;

    return 0;
}