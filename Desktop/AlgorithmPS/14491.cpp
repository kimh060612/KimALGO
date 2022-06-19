#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int a;
    cin >> a;

    vector<int> ANS;
    while (a > 0) 
    {
        int mod = a % 9;
        ANS.push_back(mod);
        a /= 9;
    }

    reverse(ANS.begin(), ANS.end());

    for (int i = 0; i < ANS.size(); i++) cout << ANS[i];
    cout << endl;

    return 0;
}