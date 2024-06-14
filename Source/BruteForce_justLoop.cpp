#include "iostream"
#include "math.h"
#include "vector"
#include "array"

using namespace std;

int main()
{
	int N = 0, M = 0, number, sum, sumMax = 0;
	array<int, 100> Cards;
	cin >> N >> M;


	for (int i = 0; i < N; i++)
	{
		cin >> number;
		Cards[i] = number;
	}

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				sum = Cards[i] + Cards[j] + Cards[k];
				if (sum > sumMax && sum <= M)
				{
					sumMax = sum;
				}
			}
		}
	}

	cout << sumMax;

	return 0;
}