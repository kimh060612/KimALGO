#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;
using ll = long long;
using iip = pair<ll, ll>;

ifstream fin("input.txt");

int n;
iip P[100001];

ll getSquareDistance(iip x, iip y) {
    int dx = x.first - y.first;
    int dy = x.second - y.second;
    return (ll)dx * (ll)dx + (ll)dy * (ll)dy;
}

bool compareByCoordX(const iip &i ,const iip &j) {
    if (i.first == j.first) return i.second < j.second;
    return i.first < j.first;
}

bool compareByCoordY(const iip &i ,const iip &j) {
    if (i.second == j.second) return i.first < j.first;
    return i.second < j.second;
}

ll min(ll a, ll b) { return a < b ? a : b; }
ll getMinDistance(int s, int e) {
    if (s >= e) return 987654321; // base case: range out of bound
    if (s + 1 == e) return getSquareDistance(P[s], P[e]); // base case: there only two points to be investigated left
    int mid = (s + e) / 2;
    ll b = getMinDistance(s, mid);
    ll c = getMinDistance(mid, e);
    ll minDist = min(b, c);

    // sort(P + s, P + e, compareByCoordX);
    sort(P + s, P + e, compareByCoordY);
    for (int i = s; i <= e; i++) {
        for (int j = i; j <= e; j++) {
            if (i == j) continue;
            if (abs(P[i].first - P[j].first) > minDist || abs(P[i].second - P[j].second) > minDist) break;
            minDist = min(minDist, getSquareDistance(P[i], P[j]));
        }
    }

    return minDist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> P[i].first >> P[i].second;
    }
    sort(P + 1, P + 1 + n, compareByCoordX);
    
    ll res = getMinDistance(1, n);
    if (res == 987654321) res = 0;
    cout << res << endl;

    return 0;
}