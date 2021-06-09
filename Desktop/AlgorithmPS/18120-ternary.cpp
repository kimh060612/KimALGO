#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N, A;
vector<pair<pair<int, int>, int>> V;
double MAX_R = 0.;
//double Summation[100001];

bool compare(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
{
    double a1 = a.first.second * a.first.second + a.first.first * a.first.first;
    double b1 = b.first.second * b.first.second + b.first.first * b.first.first;
    if (a1 == b1) return a.second < b.second;
    else return a1 < b1;
}

double distance(int x, int y)
{
    return sqrt(x *x + y *y);
}

double profit(double R)
{
    double revenue = 0.;
    for (int i = 0; i < N; i++)
    {
        double d = distance(V[i].first.first, V[i].first.second);
        if (d >= R) break;
        else {
            revenue += (R - d) * (double)V[i].second;
        }
    }
    return revenue - A * R * R;
}

int main()
{
    cin >> N >> A;
    for (int i = 1; i <= N; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        V.push_back({{x, y}, w});
        MAX_R += w;
        //Summation[i] = Summation[i - 1] + distance(x, y) * (double)w;
    }
    MAX_R = MAX_R / (2.0 * (double)A);
    sort(V.begin(), V.end(), compare);
    
    double s = 0., e = MAX_R;
    while (e - s > e * 1e-6)
    {
        double a = (2 * s + e) / 3.0;
        double b = (s + 2 * e) / 3.0;
        if (profit(a) > profit(b))e = b;
        else s = a;
    }

    double ans = profit(s);
    ans = (ans > MAX_R ? ans : profit(MAX_R));
    std::cout << fixed;
    std::cout.precision(6);
    if (ans < 0) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}