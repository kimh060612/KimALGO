#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> Q;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        if (a != 0)
        {
            Q.push(a);
        }
        else if (a == 0)
        {
            if (Q.empty()) cout << 0 << "\n";
            else {
                cout << Q.top() << "\n";
                Q.pop();
            }
        }
    }
    return 0;
}