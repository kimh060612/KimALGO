#include <iostream>
#include <string>
#include <map>

using namespace std;

int N, M;
string S[100001];
string K[100001];
map <string, int> Map1;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> S[i];
        Map1.insert(pair<string, int>(S[i], i));
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> K[i];
        if ( 48 <= K[i][0] && K[i][0] <= 58)
        {
            int k = stoi(K[i]);
            cout << S[k] << "\n";
        }
        else {
            cout << Map1[K[i]] << "\n";
        }
    }

    return 0;
}