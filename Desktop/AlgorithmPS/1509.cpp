#include <iostream>
#include <string>
#include <algorithm>
#define MAX 2501

using namespace std;

int PDL[MAX][MAX];
int DP[MAX];

int main()
{
    string S;
    cin >> S;
    S.insert(0, " ");
    int N = S.length();
    for (int i = 1; i <= N; i++)PDL[i][i] = 1;
    for (int i = 1; i < N; i++)if (S[i] == S[i + 1])PDL[i][i + 1] = 1;
    
    for (int i = 2; i < N; i++)
    {
        for (int j = 1; j <= N - i; j++)
        {
            if (S[j] == S[j + i] && PDL[j + 1][j + i - 1])PDL[j][j + i] = 1;
        }
    }

    for (int i = 1; i < N; i++)
    {
        DP[i] = 987654321;
        for (int j = 1; j <= i; j++)
        {
            if (PDL[j][i])DP[i] = min(DP[i], DP[j - 1] + 1);
        }
    }
    cout << DP[N - 1] << endl;
    return 0;
}