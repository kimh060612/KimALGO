#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int N,M;
int A[MAX];
vector<int> MINTree;

void init(int node, int s, int e)
{
    if (s == e)
    {
        MINTree[node] = A[s];
        return;
    }
    int mid = (s + e) / 2;
    init(node * 2, s, mid);
    init(node * 2 + 1, mid + 1 , e);
    MINTree[node] = min(MINTree[node * 2], MINTree[node * 2 + 1]);
    return;
}

int find(int node, int a, int b, int left, int right)
{
    if (left > b || right < a) return 2147483647;
    if (a <= left && right <= b) return MINTree[node];
    int mid = (left + right) / 2;
    int l,r;
    l = find(node * 2, a, b, left, mid);
    r = find(node * 2 + 1, a, b, mid + 1, right);
    return min(l, r);
}


int main()
{
    scanf("%d %d", &N, &M);

    int N_tree = (1 << ((int)ceil(log2(N)) + 1));
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
        int ans = find(1, a - 1, b - 1, 0, N - 1);
        printf("%d\n", ans);
    }
    return 0;
}