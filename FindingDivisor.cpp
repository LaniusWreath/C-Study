#include "iostream"

using namespace std;

int main()
{
	int N, K, count = 0, currentNumber = 1;

	cin >> N >> K;

	while (count != K)
	{
		if (currentNumber > N)
		{
			cout << "0";
			return 0;
		}

		if (N % currentNumber == 0)
		{
			count++;
		}
		currentNumber++;
	}

	cout << currentNumber - 1;
	return 0;
}