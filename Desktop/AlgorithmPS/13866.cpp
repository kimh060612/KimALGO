#include <iostream>

using namespace std;

int main()
{
    int A[4];
    cin >> A[0] >> A[1] >> A[2] >> A[3];
    int diff = 987654321;
    int sum = A[0] + A[1] + A[2] + A[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            int a = A[i] + A[j];
            int b = sum - a;
            diff = min(diff, abs(a - b));
        }
    }
    cout << diff << endl;
    return 0;
}