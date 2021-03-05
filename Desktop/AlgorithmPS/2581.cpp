#include <iostream>
#include <cmath>

using namespace std;

bool sosu(int num) {
	if (num < 2) return false;
	int a = (int) sqrt(num);
	for (int i = 2; i <= a; i++) if (num % i == 0) return false;
	return true;
}

int main()
{
    int N, M;
    cin >> N >> M;
    int cnt = 0, sum = 0, min;
    for (int i = N; i <= M; i++)
    {
        if (sosu(i))
        {
            cnt ++;
            sum += i;
            if (cnt == 1)min = i;
        }
    }
    if (cnt != 0)
    {
        cout << sum << endl;
        cout << min << endl;
    }
    else 
    {
        cout << -1 << endl;
    }
    
    return 0;
}