#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int input = 255;
	int num;
	int n = 0;

	while (input) {
		n = 0;
		cin >> num;
		if (num == 0)
			break;

		int len = (int)sqrt(num);

		for (int i = 1; i <= len; i++) {
			if (i*i == num) {
				n++;
				continue;
			}
			for (int j = i; j <= len; j++) {
				if (i*i + j * j == num) {
					n++;
					break;
				}
				else if (i*i + j * j > num)
					break;

				for (int k = j; k <= len; k++) {
					if (i*i + j * j + k * k == num) {
						n++;
						break;
					}
					else if (i*i + j * j + k * k > num)
						break;

					for (int l = k; l <= len; l++) {
						if (i*i + j * j + k * k + l * l == num) {
							n++;
							break;
						}
						else if (i*i + j * j + k * k + l * l > num)
							break;
					}
				}
			}
		}

		cout << n << '\n';
		input--;
	}

	return 0;
}