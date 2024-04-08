#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
	int Size, Quotiont;
	string Word = "long";

	cin >> Size;
	Quotiont = Size / 4;

	for (int i = 0; i < Quotiont; i++)
	{
		cout << Word <<" ";
	}
	cout << "int";

	return 0;
}