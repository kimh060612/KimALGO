#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int contest_num;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> contest_num;

	int index_check = contest_num;
	long long prize_sum_store = 0;

	long long max_value_store = -1;

	for (int i = 0; i < contest_num; i++) {
		long long limit_num, prize;
		cin >> limit_num >> prize;
		if (prize_sum_store > limit_num) {
			index_check = i + 1;

			if (max_value_store > prize) {
				if (max_value_store >= prize_sum_store - limit_num) {
					prize_sum_store = prize_sum_store - max_value_store + prize;
				}
			}
			break;
		}
		prize_sum_store += prize;
		max_value_store = max(max_value_store, prize);
	}

	for (int i = index_check; i < contest_num; i++) {
		long long limit_num, prize;
		cin >> limit_num >> prize;

		if (prize_sum_store > limit_num) {
			cout << "Zzz\n";
			return 0;
		}
		else {
			prize_sum_store += prize;
		}
	}

	cout << "Kkeo-eok\n";
	return 0;
}