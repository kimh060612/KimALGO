#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        char tmp[4];
        cin >> tmp;
        int a = tmp[0] - 48;
        int b = tmp[2] - 48;
        cout << a + b << endl;
    }
    return 0;
}