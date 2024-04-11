#include <iostream>

using namespace std;

int temp = 0;
int Array[31] = { 0, };

void F_InitializeArray(int* TargetArray, int Size)
{
	for (int cur = 0; cur < Size; cur++)
	{
		cin >> temp;
		TargetArray[temp] = 1;
	}
}

int main() 
{
	F_InitializeArray(Array, 28);

	for (int cur = 1; cur < 31; cur++)
	{
		if (Array[cur] != 1)
		{
			cout << cur << "\n";
		}
	}
	return 0;
}
