#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cout << (N / 5) + ( N % 5 == 0 ? 0 : 1) << endl;
    return 0;
}