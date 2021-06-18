#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char S[100];
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> S;
        int score = 0, ans = 0, N = strlen(S);
        for (int j = 0; j < N; j++)
        {
            if (S[j] == 'O')score ++;
            if (S[j] == 'X' || j == N - 1) 
            {
                ans += score * (score + 1) / 2;
                score = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}