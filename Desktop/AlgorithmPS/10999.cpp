#include <iostream>
#include <vector>
#define MAX 1000001

using namespace std;
typedef long long ll;

ll A[MAX];
int N, M, K;
vector<ll> Tree, lazy;

void init(int node, int s, int e)
{
    if (s == e)
    {
        Tree[node] = A[s];
        return;
    }

    int mid = (s + e) / 2;
    init(node * 2, s, mid);
    init(node * 2 + 1, mid + 1, e);
    Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
}

void update_lazy(int node, int s, int e)
{
    if (lazy[node] != 0)
    {
        Tree[node] += (e - s + 1)*lazy[node];
        if (s != e)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

ll sum(int node, int a, int b, int left, int right)
{
    update_lazy(node, left, right);
    if (b < left || right < a)return 0;
    if (a <= left && right <= b) return Tree[node];

    ll l ,r;
    int mid = (left + right) / 2;
    l = sum(node * 2, a, b, left, mid);
    r = sum(node * 2 + 1, a, b, mid + 1, right);
    return l + r;
}

void update(int node, int a, int b, int left, int right, ll diff)
{
    update_lazy(node, left, right);
    if (b < left || right < a)return;
    if (a <= left && right <= b)
    {
        Tree[node] += (right - left + 1) * diff;
        if (left != right)
        {
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    int mid = (left + right) / 2;
    update(node * 2, a, b, left, mid, diff);
    update(node * 2 + 1, a, b, mid + 1, right, diff);
    Tree[node] = Tree[node * 2] + Tree[node * 2 + 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    Tree.resize(N * 4);
    lazy.resize(N * 4);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    init(1, 0, N - 1);
    M += K;

    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b, c;
            ll d;
            cin >> b >> c >> d;
            update(1, b - 1, c - 1, 0, N - 1, d);
        }
        else
        {
            int b, c;
            cin >> b >> c;
            cout << sum(1, b - 1, c - 1, 0, N - 1) << endl;
        }
    }
    return 0;
}