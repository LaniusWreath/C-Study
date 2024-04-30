#include <iostream>
#include <string>
using namespace std;

int Amount, a, b, S;
int MaxtrixA[100][100] = { 0 };

int main()
{
	cin >> Amount;
	for (int i = 0; i < Amount; i++)
	{
		cin >> a >> b;
		for (int x = a; x < a + 10; x++)
		{
			for (int y = b; y < b + 10; y++)
			{
				MaxtrixA[x][y] += 1;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (MaxtrixA[i][j] > 0)
			{
				S = S + 1;
			}
		}
	}

	cout << S;

	return 0;
}