#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    vector<int> ans;
    cin >> s;

    for (int i = s.size() - 1; i >= 0; i -= 3)
    {
        int k = 0;
        for (int j = 0; j < 3 && i - j >= 0; j++)
        {
            if(s[i - j] - '0' == 1) k += 1 << j;
        }
        ans.push_back(k);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}