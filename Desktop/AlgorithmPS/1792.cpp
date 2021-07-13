#include <iostream>
#include <vector>

using namespace std;

int mu[1000010], muSum[1000010];
void Mobius() {
    mu[1] = 1;
    for(int i = 1; i <= 1000000; i++) {
        for(int j = 2 * i; j <=1000000; j += i) {
            mu[j] -= mu[i];
        }
    }
    muSum[1] = mu[1];
    for (int i = 2; i <= 1000000; i++) muSum[i] = muSum[i - 1] + mu[i];
}

long long answer(int a, int b, int d)
{
    long long j = 0, ans = 0;
    int ad = (int)(a/d);
    int bd = (int)(b/d);
    int M = min(ad, bd);
    for (int i = 1; i <= M; i = j + 1)
    {
        j = min((int)(ad / (int)(ad / i)), (int)(bd / (int)(bd / i)));
        ans += (long long)(ad / i) * (bd / i) * (muSum[j] - muSum[i - 1]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Mobius();
    int t;
    cin >> t;
    for (int o = 1; o <= t; o++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        long long ans = 0, j = 0, k = 0;
        ans = answer(a, b, d);
        cout << ans << "\n";
    }
    return 0;
}