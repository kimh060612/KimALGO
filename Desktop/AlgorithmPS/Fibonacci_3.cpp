#include <iostream>
#define MOD 1500000
#define MAX 1000000

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long F1 = 0, F2 = 1, F3 = 1;
    for (int i = 1; i < n % MOD; i++)
    {
        F3 = (F1 + F2) % MAX;
        F1 = F2;
        F2 = F3;
    }
    if (n == 0)cout << 0 << endl;
    else cout << F3%MAX << endl;
    return 0;
}