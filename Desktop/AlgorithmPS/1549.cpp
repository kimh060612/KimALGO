#include <iostream>

using namespace std;
typedef long long ll;

int N;
ll A[3001], Sum[3001];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) Sum[i] = Sum[i - 1] + A[i];
    ll ans = 9e15, ans_index = -1;
    for (int k = 1; k <= (int)(N/2) + 1; k++)
    {
        for (int j = 1; j + k - 1 <= N; j++)
        {
            for (int i = 1; i + k <= j; i++)
            {
                ll Sik = Sum[i + k - 1] - Sum[i - 1];
                ll Sjk = Sum[j + k - 1] - Sum[j - 1];
                ll Diff = (ll)abs(Sik - Sjk);
                if (Diff <= ans)
                {
                    ans = Diff;
                    ans_index = max(ans_index, (ll)k);
                }
            }
        }
    }
    cout << ans_index << endl;
    cout << ans << endl;
    return 0;
}