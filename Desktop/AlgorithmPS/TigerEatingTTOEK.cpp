#include <iostream>

using namespace std;

int F[31];

int main()
{
    int D, K;
    int first, second;
    cin >> D >> K;
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= D; i++)
    {
        F[i] = F[i - 2] + F[i - 1];
    }

    for (first = 1; first < K; first ++)
    {
        if ((K - F[D-2]*first)%F[D - 1] == 0)
        {
            second = (K - F[D-2]*first)/F[D - 1];
            break;
        }
    }    

    cout << first << endl << second << endl;

    return 0;
}