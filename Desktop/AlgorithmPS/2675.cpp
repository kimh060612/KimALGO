#include <iostream>
#include <string>

using namespace std;

int t;

int main()
{
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int num;
        string S;
        cin >> num;
        cin >> S;
        for (int j = 0; j < S.size(); j++)
        {
            for (int k = 1; k <= num; k++) cout << S[j];
        }
        cout << endl;
    }
    return 0;
}