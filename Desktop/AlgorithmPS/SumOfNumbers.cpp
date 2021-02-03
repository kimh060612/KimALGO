#include <iostream>

using namespace std;

int main()
{
    int N;
    char C[101];
    cin >> N;
    cin >> C;

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        answer += C[i] - '0';
    }

    cout << answer << endl;

    return 0;
}