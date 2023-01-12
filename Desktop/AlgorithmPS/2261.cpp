#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;
using ll = long long;
using iip = pair<ll, ll>;

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

    sort(P + s, P + e, compareByCoordX);
    vector<iip> Indicies;
    for (int i = s; i <= e; i++) {
        if (minDist <= abs(P[i].first - P[mid].first)) continue;
        Indicies.push_back(P[i]);
    }
    if (Indicies.size() == 0) return minDist;
    sort(Indicies.begin(), Indicies.end(), compareByCoordY);
    for (int i = 0; i < Indicies.size(); i++) {
        iip p1 = Indicies[i];
        for (int j = i + 1; j < Indicies.size(); j++) {
            iip p2 = Indicies[j];
            if ((p1.second - p2.second) * (p1.second - p2.second) > minDist) break;
            minDist = min(minDist, getSquareDistance(p1, p2));
        }
    }
    return minDist;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> P[i].first >> P[i].second;
    }
    sort(P + 1, P + 1 + n, compareByCoordX);
    
    ll res = getMinDistance(1, n);
    if (res == 987654321) res = 0;
    cout << res << endl;

    return 0;
}