#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vt;
    vt.push_back(-987654321);
    int N, ans = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int x;
        cin >> x;
        if (vt.back() < x)
        {
            vt.push_back(x);
            ans ++;
        }
        else
        {
            auto it = lower_bound(vt.begin(), vt.end(), x);
            *it = x;
        }
    }
    cout << ans << endl;
    return 0;
}