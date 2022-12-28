#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main() {
	string s;
	cin >> s;
	if (s[0] >= '1' && s[0] <= '9') {
		cout << s;
	}
	else if (s[1] == 'x') {
		s.erase(0, 2);
		int total = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] <= '9')
				total += ((s[i] - '0') * pow(16, s.size() - 1 - i));
			else
				total += ((s[i] - 'a' + 10) * pow(16, s.size() - 1 - i));
		}
		cout << total;
	}
	else {
		s.erase(0, 1);
		int total = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			total += ((s[i] - '0') * pow(8, s.size() - 1 - i));
		}
		cout << total;
	}
	return 0;
}