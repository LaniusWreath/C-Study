#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {

	int Amount, Array[100], Number, count = 0;
	cin >> Amount;

	for (int i = 0; i < Amount; i++)
	{
		cin >> Array[i];
	}

	cin >> Number;

	for (int i = 0; i < Amount; i++)
	{
		if (Number == Array[i])
		{
			count += 1;
		}
	}

	cout << count;

	return 0;
}