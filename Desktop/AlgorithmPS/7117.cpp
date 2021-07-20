#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;

int N;
int dx[3] = {0, 2, 7};
int check[500001];

string BFS(int x)
{
    queue<pair<string, int>> Q;
    string S = to_string(x);
    Q.push({S, x % N});
    check[x % N] = 1;

    string ans = "-1";

    while (!Q.empty())
    {
        string X = Q.front().first;
        int now = Q.front().second;
        Q.pop();

        if (now == 0) {
            ans = X;
            break;
        }

        for (int i = 0; i < 3; i++)
        {
            int next = ((now * 10) % N + dx[i] % N) % N;
            if (X.length() + 1 <= 20 && !check[next]) {
                string nx = X + to_string(dx[i]);
                Q.push({nx, next});
                check[next] = 1;
            }
        }
    }
    return ans;
}

int main()
{
    cin >> N;
    memset(check, 0, sizeof(check));
    string ans2 = BFS(2);
    memset(check, 0, sizeof(check));
    string ans7 = BFS(7);
    string ans;

    if (ans2.compare("-1") == 0 && ans7.compare("-1") == 0) {
        cout << "NAV" << endl;
        return 0;
    }

    if (ans2.compare("-1") != 0 && ans7.compare("-1") != 0) {
        if (ans2.length() < ans7.length()) ans = ans2;
        else if (ans2.length() > ans7.length()) ans = ans7;
        if (ans2.length() == ans7.length())ans = ans2;
        cout << ans << endl; 
        return 0;
    }
    
    if (ans2.compare("-1") == 0 && ans7.compare("-1") != 0) {
        cout << ans7 << endl;
        return 0;
    }
    if (ans2.compare("-1") != 0 && ans7.compare("-1") == 0) {
        cout << ans2 << endl;
        return 0;
    }
}