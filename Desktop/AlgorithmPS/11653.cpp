#include <iostream>
#define MAX 10000000

using namespace std;
using ll = long long;

ll N;
int isPrime[MAX + 5];

void init() {
    for(int x = 2; x <= MAX; x++){
        if(isPrime[x] == 1) continue;
        for (int u = 2*x; u <= MAX; u += x){
            isPrime[u] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> N;
    for (int i = 2; i <= MAX; i++) {
        if (i > N) break;
        if (!isPrime[i]) {
            while (N % i == 0) {
                cout << i << "\n";
                N /= i;
            }
        }
    }
    return 0;
}