#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int N,M;
int A[MAX];
vector<int> MAXTree, MINTree;

void init(int node, int s, int e)
{
    if (s == e)
    {
        MAXTree[node] = MINTree[node] = A[s];
        return;
    }
    int mid = (s + e) / 2;
    init(node * 2, s, mid);
    init(node * 2 + 1, mid + 1 , e);
    MINTree[node] = min(MINTree[node * 2], MINTree[node * 2 + 1]);
    MAXTree[node] = max(MAXTree[node * 2], MAXTree[node * 2 + 1]);
    return;
}

pair<int, int> find(int node, int a, int b, int left, int right)
{
    if (left > b || right < a) return make_pair(2147483647, 0);
    if (a <= left && right <= b) return make_pair(MINTree[node], MAXTree[node]);
    int mid = (left + right) / 2;
    pair<int, int> l,r;
    l = find(node * 2, a, b, left, mid);
    r = find(node * 2 + 1, a, b, mid + 1, right);
    return make_pair(min(l.first, r.first), max(l.second, r.second));
}

int main()
{
    scanf("%d %d", &N, &M);

    int N_tree = (1 << ((int)ceil(log2(N)) + 1));
    MAXTree.resize(N_tree);
    MINTree.resize(N_tree);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    init(1, 0, N - 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        pair<int, int> ans = find(1, a - 1, b - 1, 0, N - 1);
        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}