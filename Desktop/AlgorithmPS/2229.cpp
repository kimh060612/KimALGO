#include <iostream>
#include <memory.h>
#define INF 1001
#define min(a, b) a > b ? b : a
#define max(a, b) a > b ? a : b

using namespace std;

int N;
int A[INF], DP[INF];

int maxDifference(int idx)
{

    if (idx > N)return 0;

    int &result = DP[idx];

    if (result != -1)return result;

    result = 0;

    int low = 987654321, high = -1;

    for (int i = idx; i <= N; i++)
    {
        low = min(low, A[i]);
        high = max(high, A[i]);
        result = max(result, (high - low) + maxDifference(i + 1));
    }

    return result;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }

    memset(DP, -1, sizeof(DP));
    int answer = maxDifference(1);
    cout << answer << endl;
}