#include <iostream>

using namespace std;

int N, M, i, j;
int Array[101] = { 0, };

void F_Swap(int idx1, int idx2, int* TargetArray)
{
	int temp;
	temp = TargetArray[idx1];
	TargetArray[idx1] = TargetArray[idx2];
	TargetArray[idx2] = temp;
}

void F_InitializeArray(int* TargetArray, int Size)
{
	for (int cur = 1; cur <= Size; cur++)
	{
		TargetArray[cur] = cur;
	}
}

int main() {

	cin >> N >> M;
	F_InitializeArray(Array, N);

	for (int cur = 0; cur < M; cur++)
	{
		cin >> i >> j;
		F_Swap(i, j, Array);
	}

	for (int cur = 1; cur <= N; cur++)
	{
		cout << Array[cur] << " ";
	}

	return 0;
}
