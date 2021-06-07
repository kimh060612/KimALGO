#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
typedef long long ll;

int N, K, A[16];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> A[i];
    }

    ll ans = 0;
    for (ll i = 0; i < (1 << K); i++)
    {
        ll odev = 0;
        ll delta = 0;
        for (int j = 0; j < K; j++)
        {
            if (i & (1 << j))
            {
                odev ++;
                if (delta == 0)delta = A[j];
                else {
                    delta = delta * A[j] / gcd(delta, A[j]);
                }
            }            
        }
        if (odev) {
            ll a = N / delta;
            if (odev % 2 == 0)a *= -1;
            ans += a;
        }
    }
    cout << N - ans << endl;
    return 0;
}

// int mu[100001], isInList[101];
// vector<int> S;

// int gcd(int a, int b)
// {
//     return b ? gcd(b, a % b) : a;
// }

// void Mobius()
// {
//     mu[1] = 1;
//     for(int i = 1; i <= 100000; i++)
//     {
//         for(int j = 2 * i; j <=100000; j += i) 
//         {
//             mu[j] -= mu[i];
//         }
//     }
// }

// int main()
// {
//     Mobius();
//     cin >> N >> K;
//     for (int i = 1; i <= K; i++)
//     {
//         cin >> A[i];
//         isInList[i] = 1;
//         S.push_back(A[i]);
//     }

//     for (int i = 1; i <= K; i++)
//     {
//         for (int j = i + 1; j <= K; j++)
//         {
//             int tmp = A[i] * A[j] / gcd(A[i], A[j]);
//             if (max(A[i], A[j]) % min(A[i], A[j]) == 0)
//             {
//                 int M = A[i] > A[j] ? i : j;
//                 vector<int>::iterator it = S.begin();
//                 it += M - 1;
//                 S.erase(it);
//                 isInList[M] = 0;
//                 continue;
//             }
//             if (isInList[tmp] || tmp > N) continue;
//             else {
//                 isInList[tmp] = 1;
//                 S.push_back(tmp);
//             }
//         }
//     }

//     int ans = 0;
//     for (int i = 0; i < S.size(); i++)
//     {
//         ans += mu[S[i]] * (N / S[i]);
//     }
//     ans *= -1; 
//     cout << N - ans << endl;
//     return 0;
// }