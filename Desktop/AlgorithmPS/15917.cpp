#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int a;
        cin >> a;
        if (((a & ((-1) * a)) == a))cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}