#include <iostream>
#include <queue>
#include <string>
#include <string.h>

using namespace std;
using ll = long long;
using slp = pair<string, ll>;

int check[20005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll N;
        memset(check, 0, sizeof(check));
        cin >> N;
        queue<slp> Q;
        Q.push({ "1", 1 });
        check[1] = 1;
        while (!Q.empty()) {
            string state = Q.front().first;
            ll x = Q.front().second;
            Q.pop();

            if (state.length() > 100) {
                cout << "BRAK\n";
                break;
            }
            if (x == 0) {
                cout << state << "\n";
                break;
            }

            ll addZero = (x * 10) % N;
            string retZero = state + "0";
            if (!check[addZero]) {
                check[addZero] = 1;
                Q.push({ retZero, addZero });
            } 
            ll addOne = (x * 10 + 1) % N;
            string retOne = state + "1";
            if (!check[addOne]) {
                check[addOne] = 1;
                Q.push({ retOne, addOne });
            }
        }
    }
    return 0;
}