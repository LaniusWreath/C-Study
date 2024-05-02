#include <iostream>
#include <algorithm>

using namespace std;

//2^2 -> 3^2 -> 5^2 -> 9^2 -> 17^2

int N, Point=2, Blank, Total;

int main()
{
	cin >> N;

	Total = pow(Point, 2);
	cout << Total;

	return 0;
}
