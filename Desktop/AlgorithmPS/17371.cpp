#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using iip = pair<int, int>;

int N;
iip A[1001];

double distance(iip a, iip b) {
    int dy = b.first - a.first;
    int dx = b.second - a.second;
    return sqrt(dx * dx + dy * dy);
}

bool compare(const iip &i, const iip &j) {
    double a = distance(i, {0, 0});
    double b = distance(j, {0, 0});
    if (a == b) return i.first < j.first;
    return a < b;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    sort(A + 1, A + 1 + N, compare);

    cout.precision(10);
    cout << fixed;
    double ans = 987654321;
    int aindex = 1;
    for (int i = 1; i <= N; i++) {
        double _max = -1;
        int mindex = i;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            double _dist = distance(A[i], A[j]);
            if (_max < _dist) {
                _max = _dist;
                mindex = j;
            }
        }
        if (ans > _max) {
            ans = _max;
            aindex = i;
        }
    }

    cout << A[aindex].first << " " << A[aindex].second << endl;

    return 0;
}