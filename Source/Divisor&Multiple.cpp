#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int num1 = -1, num2 = -1;

	while (true)
	{
		cin >> num1 >> num2;

		if (num1 == 0 && num2 == 0)
		{
			break;
		}

		if (num1 > num2)
		{
			if (num1 % num2 == 0)
			{
				cout << "multiple" << "\n";
			}
			else
			{
				cout << "neither" << "\n";
			}
		}
		else
		{
			if (num2 % num1 == 0)
			{
				cout << "factor" << "\n";
			}
			else
			{
				cout << "neither" << "\n";
			}
		}
	}

	return 0;
}
