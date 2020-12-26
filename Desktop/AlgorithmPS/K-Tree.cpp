#include <iostream>
// 이번 문제는 printf가 다 했다 씨발
using namespace std;
typedef long long ll;

int main()
{
    long long N, K, Q;
    scanf("%lld %lld %lld", &N, &K, &Q);
    for (int i = 0; i < Q; i++)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        a -= 1; b -= 1;
        long long CRD_a = 0;
        long long CRD_b = 0;

        if (K == 1)
        {
            printf("%lld \n", abs(a - b));
            continue;
        }

        while (1)
        {
            if (a != b)
            {
                if (a > b)
                {
                    a = (a - 1)/ K;
                    CRD_a ++;
                }
                else
                {
                    b = (b - 1)/K;
                    CRD_b ++;
                }
            }
            else break;
        }
        printf("%lld \n", CRD_b + CRD_a);
    }
    return 0;
}