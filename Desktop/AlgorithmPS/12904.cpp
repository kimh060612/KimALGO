#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int numSA, numSB;
int numTA, numTB;
string S, T;

int main()
{
    cin >> S >> T;
    bool ans;
    while (T.length() > S.length())
    {
        if (T.back() == 'A') T.pop_back();
        else {
            T.pop_back();
            reverse(T.begin(), T.end());
        }
    }
    if (S == T)cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}