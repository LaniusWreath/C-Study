#include <iostream>
#include <string>
using namespace std;

int CurrentPiece;
int ArrayPiece[6] = { 1,1,2,2,2,8 };

int main()
{
	for (int i = 0; i < 6; i++)
	{
		cin >> CurrentPiece;
		cout << ArrayPiece[i] - CurrentPiece << " ";
	}
	return 0;
}