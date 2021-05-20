#include <iostream>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int P[501], E[501][501];
int in[501];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        memset(E, 0, sizeof(E));
        memset(in, 0, sizeof(in));
        cin >> N;
        for (int i = 1; i <= N; i++)
        {
            cin >> P[i];
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = i + 1; j <= N; ++j) {
                E[P[i]][P[j]] = 1;
                in[P[j]]++;
            }
        }

        cin >> M;
        for (int i = 1; i <= M; i++)
        {
            int a, b;
            cin >> a >> b;
            if (E[a][b]) {
                E[a][b] = 0;
                E[b][a] = 1;
                in[b]--, in[a]++;
            }
            else {
                E[b][a] = 0;
                E[a][b] = 1;
                in[a]--, in[b]++;
            }
        }

        queue<int> Q;
        for (int i = 1; i <= N; i++)
        {
            if (!in[i]) Q.push(i);
        }

        bool certain = true;
        vector<int> ans;
        while (!Q.empty())
        {
            if (Q.size() > 1) {
                certain = false;
                break;
            }

            int X = Q.front();
            Q.pop();
            ans.push_back(X);

            for (int i = 1; i <= N; i++)
            {
                if (E[X][i] != 0)
                {
                    in[i] --;
                    if (!in[i]){
                        Q.push(i);
                    }
                }
            }
        }   
        if (!certain) cout << "?" << endl;
        else if (ans.size() == N)
        {
            for (int i = 0; i < N; i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}