#include <iostream>
#include <string>

using namespace std;

string word;
int length;

int main()
{
	cin >> word;
	length = word.length();

	for (int i = 0; i < length / 2; i++)
	{
		if (word[i] != word[length - i - 1])
		{
			cout << "0";
			return 0;
		}
	}
	cout << "1";

	return 0;
}