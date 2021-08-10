#include <iostream>

using namespace std;

int A[1001];

long long gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int T;
    cin >> T;
    while (T --)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
        }   
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                sum += gcd(A[i], A[j]);
            }
        }
        cout << sum << endl;
    }
    
    return 0;
}