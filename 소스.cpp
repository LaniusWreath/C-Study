#include "iostream"
#include "math.h"
#include "vector"
#include "array"

using namespace std;

class BlackJack
{
private:
	int N, M, Sum;
	int currentMax = 0;
	vector<int> Numbers;
	vector<vector<int>> Combinations;
	vector<int> selectNumbers;

public:
	BlackJack(int initN, int initM)
	{
		this->N = initN;
		this->M = initM;
	}

	void initializeVector()
	{
		int Num = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> Num;
			Numbers.push_back(Num);
		}
	}

	void PickNumber(int count)
	{
		vector<int>& NumbersCopy = Numbers;

		if (selectNumbers.size()==3)
		{
			Combinations.push_back(selectNumbers);
			return;
		}

		for (int i = count; i < N; i++)
		{
			selectNumbers.push_back(NumbersCopy[i]);
			PickNumber(i + 1);
			selectNumbers.pop_back();
		}
	}

	int SelectMaxNumber()
	{
		int currentSumMax =0, currentSum = 0;
		for (const vector<int>& vec : Combinations)
		{
			for (const int& num : vec)
			{
				currentSum += num;
				if (currentSum > M)
				{
					break;
				}
			}

			if (currentSum >= currentSumMax && currentSum <=M)
			{
				currentSumMax = currentSum;
			}

			currentSum = 0;
		}
		return currentSumMax;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	BlackJack blackjack = BlackJack(n,m);

	blackjack.initializeVector();
	blackjack.PickNumber(0);
	int result = blackjack.SelectMaxNumber();

	cout << result;
	return 0;
}