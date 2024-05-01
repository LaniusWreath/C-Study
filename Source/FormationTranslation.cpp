#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string N;
int B, power = 0;
int currentValue, total = 0;
char currentChar;

int main()
{
	cin >> N >> B;
	power = N.length() - 1;

	for (int i = 0; i < N.length(); i++)
	{
		currentChar = N[i];
		if (isdigit(currentChar))
		{
			currentValue = static_cast<int>(N[i] - '0');
		}
		else
		{
			currentValue = static_cast<int>(N[i] - 'A') + 10;
		}

		total = total + currentValue * pow(B, power);

		power -= 1;
	}

	cout << total;

	return 0;
}

