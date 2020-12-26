#include <iostream>

using namespace std;

int main()
{
    int P, N, M;
    cin >> P;
    for (int i = 1; i <= P; i++)
    {
        cin >> N >> M;
        int count  = 0, m1 = 0, m2 = 1;
        do
        {
            int temp = m1;
            m1 = m2;
            m2 = (temp + m1)%M;
            count ++;
        } while (m1 != 0 || m2 != 1);
        cout << N << " " << count << endl;
    }    
    return 0;
}