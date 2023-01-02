#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
using ll = long long;
using ip = pair<int, int>;

struct coord {
    ip coord;
    ip relative;
};

int n;
coord A[100001];

bool compare(const ip &i, const ip &j) {
    if (i.second == j.second) return i.first < j.first;
    else return i.second < j.second;
}

bool compare_coord(const coord &i, const coord &j) {
    if ((ll)i.relative.first * (ll)j.relative.second != (ll)i.relative.second * (ll)j.relative.first) 
        return (ll)i.relative.first * (ll)j.relative.second > (ll)i.relative.second * (ll)j.relative.first;
    else return compare(i.coord, j.coord);
}

int CCW(int fx, int fy, int sx, int sy, int tx, int ty) {
    ll det = (ll)(sx - fx) * (ll)(ty - sy) - (ll)(tx - sx) * (ll)(sy - fy);
    if (det == 0) return 0;
    else if (det < 0) return -1; // 우회전
    else return 1; // 좌회전
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin >> A[i].coord.first >> A[i].coord.second;
        A[i].relative.first = 1;
        A[i].relative.second = 0;
    }

    sort(A + 1, A + 1 + n, compare_coord);

    for (int i = 2; i <= n; i++) {
        A[i].relative.first = A[i].coord.first - A[1].coord.first;
        A[i].relative.second = A[i].coord.second - A[1].coord.second;
    }

    sort(A + 2, A + 1 + n, compare_coord);

    stack<int> S;

    S.push(1);
    S.push(2);

    for (int i = 3; i <= n; i++) {
        int next_index = i;
        ip next = A[next_index].coord;
        while (S.size() >= 2) {
            int sindex = S.top();
            S.pop();
            int findex = S.top();
            ip first = A[findex].coord;
            ip second = A[sindex].coord;

            int det = CCW(first.first, first.second, second.first, second.second, next.first, next.second);
            if (det == 1) {
                S.push(sindex);
                break;
            } 
        }
        
        S.push(next_index);
    }

    cout << S.size() << endl;
    return 0;
}