#include <iostream>
#include <vector>

using namespace std;

int N;
int T[100];
pair<int, int> Tree[100];

void preorder(int now)
{
    cout << (char)(now + 64);
    if (Tree[now].first != 0) preorder(Tree[now].first);
    if (Tree[now].second != 0) preorder(Tree[now].second);
}

void inorder(int now)
{
    if (Tree[now].first != 0) inorder(Tree[now].first);
    cout << (char)(now + 64);
    if (Tree[now].second != 0) inorder(Tree[now].second);
}

void postorder(int now)
{
    if (Tree[now].first != 0) postorder(Tree[now].first);
    if (Tree[now].second != 0) postorder(Tree[now].second);
    cout << (char)(now + 64);
}

int main()
{
    cin >> N;
    T[1] = 1;
    for (int i = 1; i <= N; i++)
    {
        char a, b, c;
        int x, y, z;
        cin >> a >> b >> c;
        x = a - 64;
        y = b != '.' ? b - 64 : 0;
        z = c != '.' ? c - 64 : 0;

        Tree[x].first = y;
        Tree[x].second = z;
    }
    preorder(1);
    cout << endl;
    inorder(1);
    cout << endl;
    postorder(1);
    cout << endl;
    
    return 0;
}