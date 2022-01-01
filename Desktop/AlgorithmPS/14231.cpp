#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[5001], DP[5001];

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int ans = 0;
    v.push_back(-987654321);
    for (int i = 1; i <= n; i++) 
    {
        int x; 
        cin >> x;
        if (v.back() < x) {
            v.push_back(x);
            ans += 1;
        } 
        else {
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
    }

    cout << ans << endl;

    return 0;
}