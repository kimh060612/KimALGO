#include <iostream>
#include <vector>

using namespace std;
//solution : ���� ū ������ �����س���
int main() {
	int n;
	int sum = 0;
	vector <int> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}


	for (int i = 0; i < n - 1; i++) {
		int size = n - i;
		int max = 0;
		int idx;
		int dif;

		for (int j = 0; j < size; j++) {
			if (max < v[j]) { //���� ū ���� Ž��
				max = v[j];
				idx = j;
			}
		}

		if (idx == 0)
			dif = abs(v[idx] - v[idx + 1]); //���� ū ���� ù��° �ε����� ��
		else if (idx == size - 1)
			dif = abs(v[idx - 1] - v[idx]); //���� ū ���� �ι�° �ε����� ��
		else {
			int tmp_idx = (v[idx - 1] > v[idx + 1]) ? idx - 1 : idx + 1;
			dif = abs(v[idx] - v[tmp_idx]); //���� ū �� �� ���� �� �� ���̰� ���� �� ����
		}

		sum += dif;

		//���� ū �� ����
		for (int j = idx; j < size - 1; j++) {
			v[j] = v[j + 1];
		}
	}
	cout << sum;
}