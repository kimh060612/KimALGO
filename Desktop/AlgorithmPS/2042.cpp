#include <iostream>
#include <cmath>
#include <vector>
#define MAX 1000001

using namespace std;

int N, M, K;
long long A[MAX];
vector<long long> Tree;

long long init(int node, int left, int right)
{
    if (left == right)
    {
        Tree[node] = A[left];
        return Tree[node];
    }
    else
    {
        int mid = (left + right) / 2;
        return Tree[node] = init(node * 2, left, mid) + init(node *2 + 1, mid + 1, right);
    }
}

void update(int node, int left, int right, int pos, long long diff)
{
    if (pos < left || pos > right) return;
    Tree[node] = Tree[node] + diff;

    if (left != right)
    {
        int mid = (left + right) / 2;
        update(node * 2, left, mid, pos, diff);
        update(node * 2 + 1, mid + 1, right, pos, diff);
    }
}

long long sum(int node, int a, int b, int left, int right)
{
    if (b < left || right < a) return 0;
    if (a <= left && right <= b) return Tree[node];
    int mid = (left + right) / 2;
    return sum(node * 2, a, b, left, mid) + sum(node * 2 + 1, a, b, mid + 1, right);
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    int H = (int)ceil(log2(N) + 1);
    int tr = 1 << H;
    Tree.resize(tr);

    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }
    init(1, 0, N - 1);

    for (int i = 0; i < M + K; i++)
    {
        int a, b;
        long long c;
        scanf("%d %d %lld", &a, &b, &c);

        if (a == 1)
        {
            long long _diff = c - A[b - 1];
            A[b - 1] = c;
            update(1, 0, N - 1, b - 1, _diff);
        }

        else if (a == 2)
        {
            long long ans = sum(1, b - 1, c - 1, 0, N - 1);
            printf("%lld \n", ans);
        }
    }

    return 0;
}