#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    if ((N % 4 == 0) && ((N % 100 != 0) || (N % 400 == 0)))cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}