#include <iostream>

using namespace std;

int DP[1000001];

int main()
{
    int N;
    cin >> N;
    DP[1] = 0;
    for (int i = 2; i <= N; i++)DP[i] = 987654321;
    for (int i = 2; i <= N; i++)
    {
        if (i % 3 == 0)DP[i] = min(DP[i], DP[i / 3] + 1);
        if (i % 2 == 0)DP[i] = min(DP[i], DP[i / 2] + 1);
        DP[i] = min(DP[i], DP[i - 1] + 1);
    }

    cout << DP[N] << endl;

    int j = N;
    while (j != 1)
    {
        cout << j << " ";
        if (DP[j] == DP[j - 1] + 1)j = j - 1;
        else if (j % 2 == 0 && DP[j] == DP[j / 2] + 1)j = j / 2;
        else if (j % 3 == 0 && DP[j] == DP[j / 3] + 1)j = j / 3;
    }
    cout << 1 << endl;
    return 0;
}