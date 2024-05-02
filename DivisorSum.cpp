#include "iostream"
#include "vector"

using namespace std;


int main()
{
	int n, sum, tail = 0;

	while (true)
	{
		int array[2000] = {};
		sum = 0;
		tail = 0;

		cin >> n;

		if (n == -1)
		{
			break;
		}

		for (int i = 1; i <= n / 2; i++)
		{
			if (n % i == 0)
			{
				sum = sum + i;
				array[tail] = i;
				tail += 1;
			}
		}

		if (sum == n)
		{
			cout << n << " = ";
			for (int i = 0; i < tail; i++)
			{
				if (i != tail - 1)
				{
					cout << array[i] << " + ";
				}
				else
				{
					cout << array[i];
				}
			}
		}
		else
		{
			cout << n << " is NOT perfect.";
		}

		cout << "\n";

	}
	return 0;
}