#include <iostream>
#include <memory.h>
#define INF 91

using namespace std;

int N;
long long DP[INF];

long long FIBO(int n)
{
    if (n == 1)return 1;
    long long &ret = DP[n];
    if (ret != -1)return ret;

    ret = FIBO(n-1) + FIBO(n-2);
    return ret;
}

int main()
{

    cin >> N;

    memset(DP, -1, sizeof(DP));
    DP[1] = 1;

    cout << FIBO(N) << endl;
    return 0;
}