#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int N, SidePoint = 2, Total;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		SidePoint = SidePoint * 2 - 1;
	}

	Total = pow(SidePoint, 2);
	cout << Total;

	return 0;
}
