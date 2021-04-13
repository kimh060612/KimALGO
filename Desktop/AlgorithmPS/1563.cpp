#include <iostream>
#include <string>
#include <cstring> //memset
using namespace std;

const int MOD = 1000000;
const int MAX = 1000 + 1;
int N;
int cache[MAX][MAX][3][2]; //길이, 출석, 결석 연속, 지각

int fullAttendance(int days, int attend, int absent, int late)
{
    //기저 사례

    if (absent == 3 || late == 2)return 0;
    if (days == N) return 1;
    int &result = cache[days][attend][absent][late];
    if (result != -1)return result;

    result = fullAttendance(days + 1, attend + 1, 0, late) + fullAttendance(days + 1, attend, absent + 1, late) + fullAttendance(days + 1, attend, 0, late + 1);
    result %= MOD; //MOD로 나누기
    return result;
}

int main(void)
{
    cin >> N;
    memset(cache, -1, sizeof(cache));
    cout << fullAttendance(0, 0, 0, 0) % MOD << endl;
    return 0;
}