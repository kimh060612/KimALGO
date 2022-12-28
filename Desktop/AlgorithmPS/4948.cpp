#include <iostream>

using namespace std;

int isPrime[123456 * 2 + 1];
int Summation[123456 * 2 + 1];

void erathones()
{
    int N = 123456 * 2;
    for (int i = 1; i <= N; i++) isPrime[i] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2 * i ; j <= N; j += i)
            if (isPrime[j]) isPrime[j] = 0;
    }
}

int main()
{
    erathones();
    Summation[1] = 1;
    for (int i = 1; i <= 123456 * 2; i++) Summation[i] = Summation[i - 1] + isPrime[i];
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0) break;
        cout << Summation[2 * n] - Summation[n] << endl;
    }
    return 0;
}