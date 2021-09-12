#include <iostream>
#include <string>

using namespace std;

string A, B;
int A_[10001], B_[10001];

int main()
{
    cin >> A >> B;

    for (int i = 0; i < A.size(); i++) A_[i] = A[i] - '0';
    for (int i = 0; i < B.size(); i++) B_[i] = B[i] - '0';

    long long sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            sum += (long long)(A_[i] * B_[j]);
        }
    }

    cout << sum << endl;
    return 0;
}