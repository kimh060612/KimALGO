#include <iostream>

using namespace std;

int F[30], DPmin[30], DPmax[30];
int cnt = 3;

int minNum(int n) 
{
    if (n <= 0) return 0;
    int min_ = 987654321;
    for (int i = 2; i < cnt; i++)
    {
        if (F[i] < n)min_ = min(min_, F[i - 1] * (n / F[i]) + minNum(n - F[i] * (n / F[i])));
    }
    return min_;
}

int maxNum(int n) 
{
    if (n <= 0) return 0;
    int max_ = -987654321;
    for (int i = cnt - 1; i >= 2; i--)
    {
        if (F[i] < n)max_ = max(max_, F[i - 1] * (n / F[i]) + maxNum(n - F[i] * (n / F[i])));
    }
    return max_;
}

int main()
{
    int n;
    cin >> n;
    F[1] = 1;
    F[2] = 2;
    while (F[cnt - 1] < 20000) 
    {
        F[cnt] = F[cnt - 1] + F[cnt - 2];
        cnt ++;
    }
    
    cout << minNum(n) << " " << maxNum(n) << endl;
    return 0;
}