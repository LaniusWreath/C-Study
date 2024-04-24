#include <iostream>
#include <string>
using namespace std;

string Word;

int main()
{
	while (true)
	{
		getline(cin, Word);
		if (Word == "")
		{
			break;
		}
		cout << Word << "\n";
	}
	return 0;
}