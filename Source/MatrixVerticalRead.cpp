#include <iostream>
#include <string>
using namespace std;

char MatrixA[5][15];
string str;
int length, maxLength = 0, maxRow = 0;

int main()
{
	for (int i = 0; i < 5; i++)
	{
		getline(cin, str);
		length = str.length();
		if (length > maxLength)
		{
			maxLength = length;
			//maxRow = i;
		}
		for (int j = 0; j < str.length(); j++)
		{
			MatrixA[i][j] = str[j];
		}
	}

	for (int i = 0; i < maxLength; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (MatrixA[j][i] == NULL)
			{
				continue;
			}
			cout << MatrixA[j][i];
		}
	}

	return 0;
}