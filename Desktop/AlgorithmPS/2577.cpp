#include <iostream>

using namespace std;

int main()
{
    int ANS[10] = {0,};
    int A, B, C, D;
    cin >> A >> B >> C;
    D = A * B * C;
    int k = D;
    while (k > 0)
    {
        int d = k % 10;
        ANS[d] += 1;
        k = k / 10;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << ANS[i] << endl;
    }

    return 0;
}