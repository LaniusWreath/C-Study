#include "iostream"
#include "vector"

using namespace std;


enum E_NozzleNames
{
	A,
	B,
	C,
	D,
	E,
	F,
	NozzleCount = 6,
};


struct S_NozzleBall
{
	S_NozzleBall* PreCase;
	vector<vector<int>> CombinationVectors;
	vector<vector<int>> RestBalls;
	vector<int> TimeSpent;

	S_NozzleBall(S_NozzleBall* InitPreCase ,vector<vector<int>> InitCombinationVectors, vector<vector<int>> InitRestBalls, vector<int> InitTimeSpent)
	{
		PreCase = InitPreCase;
		CombinationVectors = InitCombinationVectors;
		RestBalls = InitRestBalls;
		TimeSpent = InitTimeSpent;
	}

	void F_InitializeCombination(vector<int> PreBalls, vector<int> NozzleSelection, int index, int count)
	{
		if (count == 4)
		{
			vector<int> Balls = PreBalls;

			for (int j = 0; j < 4; j++)
			{
				Balls[NozzleSelection[j]]--;

				if (Balls[NozzleSelection[j]] < 0)
				{
					return;
				}
			}

			CombinationVectors.push_back(NozzleSelection);
			
			
			return;
		}

		for (int i = index; i < 6; i++)
		{
			NozzleSelection[count] = i;

			F_InitializeCombination(PreBalls, NozzleSelection, i, count + 1);
		}
	}
};



int main()
{
	//공 개수 초기화
	vector<int> Balls(6);
	for (int i = 0; i < 6; i++)
	{
		cin >> Balls[i];
	}

	S_NozzleBall Head(nullptr, vector<vector<int>>(), vector<vector<int>>(), vector<int>());
	Head.F_InitializeCombination(Balls, vector<int>(4), 0, 0);
	
	
	for (const auto& comb : Head.CombinationVectors) {
		for (int nozzle : comb) {
			cout << nozzle << " ";
		}
		cout << endl;
	}
	
	return 0;
}