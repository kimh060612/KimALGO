#include <iostream>

using namespace std;
typedef long long ll;

ll N;

int main()
{
    cin >> N;
    ll PI = N;
    
    for (ll i = 2; i * i <= N; i++)
    {
        if (N % i == 0) 
            PI = PI/i * (i - 1);
        while (N % i == 0)
            N = N / i;
    }

    if (N != 1) PI = PI/N * (N - 1);
    cout << PI << endl;
    return 0;
}