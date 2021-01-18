#include <iostream>
#define MAX 1000000

using namespace std;

int N;
int DP[1000001];

int main()
{
    int ans = -1;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        DP[a] = DP[a - 1] + 1;
        ans = max(ans, DP[a]);
    }

    cout << N - ans << endl;

    return 0;
}