#include <iostream>

using namespace std;

int A[100001];
int Sum[100001];

int main()
{
    int N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    Sum[0] = 0;
    for (int i = 1; i <= N; i++)Sum[i] = Sum[i - 1] + A[i];

    int ans = -987654321;

    for (int i = K; i <= N; i++)
    {
        ans = max(ans, Sum[i] - Sum[i - K]);
    }
    cout << ans << endl;
    return 0;
}