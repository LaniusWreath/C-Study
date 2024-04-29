#include <iostream>
#include <string>

using namespace std;
int N, M;
int ArrayA[100][100], ArrayB[100][100];

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> ArrayA[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> ArrayB[i][j];
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << ArrayA[i][j] + ArrayB[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}