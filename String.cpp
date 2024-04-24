#include <iostream>

using namespace std;

string Word;
int T;
int Length;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> Word;
		Length = Word.length();
		cout << Word[0] << Word[Length - 1] << "\n";
	}
	return 0;
}