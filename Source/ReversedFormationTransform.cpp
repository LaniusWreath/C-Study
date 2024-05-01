#include <iostream>
#include <algorithm>

using namespace std;

int idx = 0, B, N = 0;
int currentQuotiont, currentRemain, total = 0;
char currentChar;
int remainArray[32];

int main()
{
	cin >> N >> B;
	currentQuotiont = N;
	while (currentQuotiont != 0)
	{
		currentRemain = currentQuotiont % B;
		currentQuotiont = currentQuotiont / B;

		remainArray[idx] = currentRemain;
		idx++;
	}
	reverse(remainArray, remainArray + idx);

	for (int i = 0; i < idx; i++)
	{
		if (remainArray[i] < 10)
		{
			currentChar = static_cast<char>(remainArray[i] + '0');
		}
		else
		{
			currentChar = static_cast<char>(remainArray[i] + 'A' - 10);
		}
		cout << currentChar;
	}
	return 0;
}