#include <iostream>

using namespace std;

int List[2001];
int DP[2001][2001];
int N, M;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> List[i];
    }

    for (int i = 1; i <= N; i++) 
    { 
        DP[i][i] = true; 
        if (List[i] == List[i - 1])DP[i - 1][i] = true;
    }

    for (int i = 2; i <= N - 1; i++) 
    { 
        for (int j = 1; j <= N - i; j++) 
        { 
            if (List[j] == List[j + i] && DP[j + 1][j + i - 1]) DP[j][j + i] = true;  
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        if (DP[s][e])cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}