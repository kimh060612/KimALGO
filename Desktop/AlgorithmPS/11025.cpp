#include <iostream>

using namespace std;

int N, K;

int main() {
    cin >> N >> K;

    int ret = 1;
    for (int i = 2; i <= N; i++) ret = (ret + K - 1) % i + 1;
	cout << ret << "\n";
    return 0;   
}