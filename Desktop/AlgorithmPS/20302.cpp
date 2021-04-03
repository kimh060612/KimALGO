#include <iostream>
#include <cmath> 
#define MAX 100000

using namespace std;

int N, prime[MAX + 1];
bool zero, yuri;

void ATfield(int x) {
    int sx = (int)sqrt(x);
    for (int i = 2; i <= sx; i++) {
        while (!(x % i)) x /= i, prime[i] ++;        
    }
    if (x > 1)prime[x] ++;
}


void ATfield2(int x) {
    int sx = (int)sqrt(x);
    for (int i = 2; i <= sx; i++) {
        while (!(x % i)) x /= i, prime[i] --;        
    }
    if (x > 1)prime[x] --;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    cin >> N;
    int num;
    char c;
    for (int i = 0; i < N; i++)
    {
        if (!i) {
            cin >> num;
            num = num < 0 ? num * (-1) : num;
            if (num == 0) {
                zero = true;
                break;
            }
            else ATfield(num);
        }
        else {
            cin >> c >> num;
            num = num < 0 ? num * (-1) : num;
            if (num == 0) {
                zero = true;
                break;
            }
            else {
                if (c == '/')ATfield2(num);
                else ATfield(num);
            }
        }
    }

    if (zero) {
        cout << "mint chocolate" << endl;
        return 0;
    } 
    else {
        for (int i = 2; i <= MAX; i++) if (prime[i] < 0) yuri = 1;
        if (yuri) cout << "toothpaste";
		else cout << "mint chocolate";
    }

    return 0;
}