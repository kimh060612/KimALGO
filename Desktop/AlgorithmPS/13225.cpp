#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        int a;
        cin >> a;
        int num = 0;
        for (int i = 1; i <= a; i++)
        {
            if (a % i == 0) num ++;
        }
        cout << a << " " << num << endl;
    }
    return 0;
}