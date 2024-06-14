#include "iostream"
#include "math.h"
#include "string"

using namespace std;

int sumNumberMembers(int Number)
{
	int sum = 0;
	int size = to_string(Number).length();
	int power = 1;

	while (power < size)
	{
		int quotient = pow(10, size - power);
		int curNumber = Number / quotient;

		sum += curNumber;
		Number = Number % quotient;

		power++;
	}
	sum += Number;

	return sum;
}

int main()
{
	int N, firstNumber, curNumber, numLength;
	string numString;

	cin >> N;

	numString = to_string(N);
	numLength = numString.size();

	curNumber = N - 9 * numLength;

	while (curNumber < N)
	{
		int sumNumber = curNumber + sumNumberMembers(curNumber);
		if (sumNumber == N)
		{
			cout << curNumber;
			return 0;
		}
		else
		{
			curNumber++;
		}
	}
	cout << 0;
	return 0;
}