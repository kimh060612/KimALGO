#include <iostream>

using namespace std;

int A[1001], N, visit[1001];

bool findCycle(int x)
{
    visit[x] = true;
    if (visit[A[x]])return true;
    return findCycle(A[x]);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        int ans = 0;
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> A[i];
            visit[i] = false;
        }
        for (int i = 1; i <= N; i++)
        {
            if (!visit[i])
            {
                if (findCycle(i))
                {
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}