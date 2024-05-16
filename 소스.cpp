#include "iostream"
#include "vector"

using namespace std;


int main()
{
	int N, number, temp, count = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		temp = 0;
		cin >> number;
		for (int j = 2; j <= number; j++)
		{
			if (number % j == 0)
			{
				temp++;
			}
		}
		if (temp == 1)
		{
			count++;
		}
	}
	
	cout << count;

	return 0;
}