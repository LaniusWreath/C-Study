#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {

	int TotalCharge, CurrentCharge = 0, a;
	int KindAmount, b;

	cin >> TotalCharge;
	cin >> KindAmount;
	
	for (char c = 0; c < KindAmount; c++)
	{
		cin >> a >> b;
		CurrentCharge += a*b;
	}

	if (CurrentCharge == TotalCharge)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}