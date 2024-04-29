//왜 잔디 안심어지지?
#include <iostream>

using namespace std;

int MatrixA[9][9];
int MaxRaw = 0, MaxColumn = 0, MaxValue = 0, CurrentValue = 0;

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> CurrentValue;
			MatrixA[i][j] = CurrentValue;
			if (MaxValue < CurrentValue)
			{
				MaxRaw = i;
				MaxColumn = j;
				MaxValue = CurrentValue;
			}
		}
	}

	cout << MaxValue << "\n" << MaxRaw + 1 << " " << MaxColumn + 1;

	return 0;
}