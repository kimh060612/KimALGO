#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 100001

using namespace std;
typedef long long ll;

int N;
ll A[MAX], maxArea;
vector<ll> Tree; 

ll init(int node, int left, int right)
{
    if (left == right)
    {
        Tree[node] = A[left];
        return Tree[node];
    }

    int mid = (left + right) / 2;
    ll l = init(node * 2, left, mid);
    ll r = init(node * 2 + 1, mid + 1, right);
    Tree[node] = min(l ,r);
}

ll find(int node, int a, int b, int left, int right)
{
    if (b < left || right < a) return 1000000001;
    if (a <= left && right <= b) return Tree[node];

    int mid = (left + right) / 2;
    ll l, r;
    l = find(node * 2, a, b, left, mid);
    r = find(node * 2 + 1, a, b, mid + 1, right);
    return min(l ,r);
}

void getMaxArea(int s, int e)
{
    ll area = find(1, s, e, 0, N - 1) * (ll)(e - s + 1);
    if (maxArea < area)maxArea = area;

    if (s == e)return;
    else
    {
        int minIndex = e;
        for (int i = s; i < e; i++) if (A[minIndex] > A[i]) minIndex = i;

        if (s <= minIndex - 1) getMaxArea(s, minIndex - 1);
        if ((minIndex + 1) <= e) getMaxArea(minIndex + 1, e);
    }
}

int main()
{
    cin >> N;
    Tree.resize(N * 4);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    init(1, 0, N - 1);
    getMaxArea(0, N - 1);

    cout << maxArea << endl;
    return 0;
}