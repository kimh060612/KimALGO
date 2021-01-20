#include <iostream>
#include <queue>
#include <deque>
#include <string.h>
#include <stdlib.h>
#define MAX 100000

using namespace std;

int N, K;
int DP[MAX +1], check[MAX + 1];

int main()
{
    cin >> N >> K;

    deque<int> Q;
    Q.push_back(N);
    int ans = 0;
    memset(check, -1, sizeof(check));
    check[N] = 1;
    while (!Q.empty())
    {
        int X = Q.front();
        Q.pop_front();

        if (X == K)
        {
            ans = DP[X];
            break;
        }

        int nx1 = X + 1;
        int nx2 = X - 1;
        int nx3 = X * 2;

        if (nx3 <= MAX && check[nx3] < 0)
        {
            DP[nx3] = DP[X];
            check[nx3] = 1;
            Q.push_front(nx3);
        }

        if (nx1 <= MAX && check[nx1] < 0)
        {
            DP[nx1] = DP[X] + 1;
            check[nx1] = 1;
            Q.push_back(nx1);
        }

        if (nx2 >= 0 && check[nx2] < 0)
        {
            DP[nx2] = DP[X] + 1;
            check[nx2] = 1;
            Q.push_back(nx2);
        }

    }

    std::cout << ans << endl;

    return 0;
}