#include <iostream>
#include <stack>

using namespace std;
using ll = long long;
using iip = pair<int, int>;

int N, A[500001];

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    stack<iip> S;
    ll cpair = 0, sheight = 0;
    for (int i = 1; i <= N; i++) {
        sheight = 1;
        int now = A[i];
        while (!S.empty() && S.top().first < now) {
            cpair += S.top().second;
            S.pop();
        }
        if (!S.empty()) {
            if(S.top().first == now){
                cpair += S.top().second;
                sheight = S.top().second + 1;
                if(S.size() > 1)++cpair;
                S.pop();
            } else{
                ++cpair;
            }
        }
        S.push({ now, sheight });
    }
    cout << cpair << "\n";
    return 0;
}