#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;
using iip = pair<int, int>;
using iiip = pair<int, iip>;

bool compare(const iiip &i, const iiip &j) {
    if (i.first == j.first) return i.second.first < j.second.first;
    return i.first < j.first;
}

int N, parent[2000], T[2000][2000];
vector<iiip> We;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    parent[u] = v;
    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) parent[i] = i;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= N - i; j++) {
            int w;
            cin >> w;
            We.push_back({ w, { i, i + j } });
        }
    }
    sort(We.begin(), We.end(), compare);

    for (int i = 0; i < We.size(); i++) {
        int w = We[i].first;
        int s = We[i].second.first, e = We[i].second.second;
        bool ret = merge(s, e);
        if (ret) {
            T[e][s] = w;
            T[s][e] = w;
        }
    }

    for (int i = 1; i <= N; i++) {
        vector<int> R;
        for (int j = 1; j <= N; j++) {
            if (T[i][j]) R.push_back(j);
        }
        cout << R.size() << " ";
        for (auto node: R) {
            cout << node << " ";
        }
        cout << "\n";
    }
    return 0;
}