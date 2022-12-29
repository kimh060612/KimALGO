#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
using ll = long long;
using lp = pair<ll, int>;

const int MAX_CANDY = 1000001;
const ll INF_NUM = 2e10 + 1;

void update_candy(vector<ll> &tree, int node, int s, int e, int candy, ll num) {
    if (candy < s || candy > e) return;
    tree[node] = tree[node] + num;
    if(s != e) {
        int mid = (s + e) / 2;
        update_candy(tree, node*2, s, mid, candy, num);
        update_candy(tree, node*2+1, mid + 1, e, candy, num);
    }
}

int query(vector<ll> &tree, int node, int s, int e, int candy_rank) {
    if (s == e)
        return s;
    int mid = (s + e) / 2;
    if (candy_rank <= tree[node * 2])
        return query(tree, node * 2, s, mid, candy_rank);
    else
        return query(tree, node * 2 + 1, mid + 1, e, candy_rank - tree[node * 2]);
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    vector<int> candy(MAX_CANDY + 1);
    cin >> n;
    vector<ll> tree(MAX_CANDY * 4);
    for (int i = 1; i <= n; i++) {
        int A;
        cin >> A;
        if (A == 1) {
            int B;
            cin >> B;
            int result = query(tree, 1, 1, MAX_CANDY, B);
            cout << result << "\n";
            update_candy(tree, 1, 1, MAX_CANDY, result, -1);
        } else {
            int B, C;
            cin >> B >> C;
            update_candy(tree, 1, 1, MAX_CANDY, B, C);
        }
    }
    return 0;
}