#include <iostream>

using namespace std;

int DP[1001];

int main()
{
    int n;
    cin >> n;
    DP[1] = 1;
    DP[2] = 0;
    DP[3] = 1;
    DP[4] = 1;
    for (int i = 5; i <= 1000; i++)
    {
        if (DP[i - 1] == 1 && DP[i - 3] == 1 && DP[i - 4] == 1) DP[i] = 0;
        else DP[i] = 1;
    }
    if (DP[n])cout << "SK" << endl;
    else cout << "CY" << endl;
    return 0;
}