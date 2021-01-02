#include <iostream>
#define MAX 500001

using namespace std;

int parent[MAX];
int find(int x);
int swap(int &a, int &b);

int main()
{
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++)parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)swap(a ,b);
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) parent[pb] = pa;
        else
        {
            cnt = i + 1;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}

int find(int x)
{
    if (parent[x] == x) return x;
    else
    {
        return parent[x] = find(parent[x]);
    }
}

int swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}