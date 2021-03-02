#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int M, A[1001] = {0,};
        cin >> M;
        double sum = 0.;
        for (int j = 1; j <= M; j++)
        {
            cin >> A[j];
            sum += (double)A[j];
        }
        sum /= (double)M;
        int count = 0;
        for (int j = 1; j <= M; j++)
        {
            if (A[j] > sum)count ++;
        }
        cout << fixed;
        cout.precision(3);
        cout << (double)count/M * 100. << "%" << endl;
    }
    return 0;
}