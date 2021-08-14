#include <iostream>

using namespace std;

int N, K;
int A[1001];

int main()
{
    cin >> N >> K;
    int cnt = 0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            if (A[j]) continue;
            A[j] = 1;
            cnt ++;
            if (cnt == K)
            {
                cout << j << endl;
                return 0;
            }
        }
    }
    return 0;
}