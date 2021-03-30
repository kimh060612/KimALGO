#include <iostream>

using namespace std;

long long factorial(int N) {
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        ans *= i;
    }
    return ans;
}

int main()
{
    int N, K;
    cin >> N >> K;
    cout << factorial(N) / (factorial(N - K) * factorial(K)) <<endl;
    return 0;
}