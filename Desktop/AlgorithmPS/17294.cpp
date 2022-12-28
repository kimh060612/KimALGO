#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char K[20];
    cin >> K;
    if (strlen(K) == 1 || strlen(K) == 2)
    {
        cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" << endl;
        return 0;
    }
    bool l = true;
    for (int i = 1; i < strlen(K) - 1; i++)
    {
        if (K[i] - K[i - 1] != K[i + 1] - K[i]) l = false;
    }
    if (l) cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" << endl;
    else cout << "흥칫뿡!! <(￣ ﹌ ￣)>" << endl;
    return 0;
}