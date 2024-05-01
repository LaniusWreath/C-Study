#include <iostream>
#include <algorithm>

using namespace std;

int cents[4] = { 25, 10, 5, 1 };
int T, C;

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> C;
		for (int j = 0; j < 4; j++)
		{
			cout << C / cents[j] << " ";
			C = C % cents[j];
		}
		cout << "\n";
	}
	return 0;
}
