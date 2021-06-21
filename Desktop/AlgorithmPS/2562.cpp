#include <iostream>

using namespace std;

int ans, ans_i;

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        int a;
        cin >> a;
        if (ans < a) 
        {
            ans = a;
            ans_i = i;
        }
    }

    cout << ans << endl << ans_i << endl;

    return 0;
}