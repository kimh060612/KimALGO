#include <iostream>
#define MAX 1000001

using namespace std;

int DP[MAX];
int N;

int min(int a, int b) { return a > b ? b : a; }

int main()
{
    int N;
    cin >> N;
    DP[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        int index;
        int Two = 987654321, Three = 987654321;
        if (i % 3 == 0) Three = DP[i / 3];
        if (i % 2 == 0) Two = DP[i / 2];

        DP[i] = min(min(Two, Three), DP[i - 1]) + 1;
    }

    cout << DP[N] << endl;

    return 0;
}
