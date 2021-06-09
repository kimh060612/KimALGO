#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, A;
vector <pair<double, int>> V;

double max(double a, double b) { return a > b ? a : b; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double W = 0, Wd = 0;
    cin >> N >> A;
    for (int i = 1; i <= N; i++)
    {
        int x, y, w;
        double d;
        cin >> x >> y >> w;
        d = sqrt(x * x + y * y);
        V.push_back({d, w});
        W += w;
        Wd += w * d;
    }
    sort(V.begin(), V.end());
    double ans = pow(W, 2) / (4 * A) - Wd;
    double r = 0;
    W = 0;
    Wd = 0;
    for (int i = 1; i <= N; i++)
    {
        double R = W / (2 * A);
        if (r <= R&& R <= V[i - 1].first) ans = max(-A * R * R + R * W - Wd, ans );
        r = V[i - 1].first;
        ans = max((-A) * r * r + W * r - Wd, ans);
        W += V[i - 1].second;
        Wd += V[i - 1].second * V[i - 1].first;
        ans = max((-A) * r * r + W * r - Wd, ans);
    }
    cout << fixed;
    cout.precision(6);
    if (ans < 0) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}