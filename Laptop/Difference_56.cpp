#include <iostream>

using namespace std;

int A, B;

int maxSum(void)
{

	int newA = 0, newB = 0;
	int copy = A;
	int multiplier = 1;

	while (copy)
	{

		int temp = copy % 10;
		if (temp == 5)temp = 6;

		newA += temp * multiplier;
		multiplier *= 10;
		copy /= 10;

	}

	copy = B;
	multiplier = 1;

	while (copy)
	{

		int temp = copy % 10;
		if (temp == 5)temp = 6;

		newB += temp * multiplier;
		multiplier *= 10;
		copy /= 10;

	}

	return newA + newB;

}

int minSum(void)
{

	int newA = 0, newB = 0;
	int copy = A;
	int multiplier = 1;

	while (copy)
	{

		int temp = copy % 10;
		if (temp == 6)temp = 5;

		newA += temp * multiplier;
		multiplier *= 10;
		copy /= 10;

	}

	copy = B;
	multiplier = 1;

	while (copy)
	{

		int temp = copy % 10;
		if (temp == 6)temp = 5;

		newB += temp * multiplier;
		multiplier *= 10;
		copy /= 10;

	}

	return newA + newB;

}

int main(void)
{

	cin >> A >> B;
	cout << minSum() << " " << maxSum() << endl;

	return 0;

}