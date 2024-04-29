#include <iostream>

using namespace std;
int N, M, i, j, temp;
int Array[101] = { 0, };

void F_InitializeArray(int* TargetArray, int Size)
{
	for (int cur = 0; cur <= Size; cur++)
	{
		Array[cur] = cur;
	}
}

void Swap(int* TargetArray, int M)
{
	for (int cur = 0; cur < M; cur++)
	{
		cin >> i >> j;

		for (int count = 0; count < (j-i+1)/2; count++)
		{
			temp = TargetArray[i+count];
			TargetArray[i+count] = TargetArray[j-count];
			TargetArray[j - count] = temp;
		}
	}
}

int main() 
{
	cin >> N >> M;

	F_InitializeArray(Array,N);
	
	Swap(Array, M);

	for (int cur = 1; cur <= N; cur++)
	{
		cout << Array[cur] << " ";
	}
	return 0;
}
