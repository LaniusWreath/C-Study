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
	vector<vector<int>> NozzleCases;
	vector<int> RestBalls;
	int TimeSpent;

	S_NozzleBall(S_NozzleBall* InitPreCase ,vector<vector<int>> InitNozzleCases, vector<int> InitRestBalls, int InitTimeSpent)
	{
		PreCase = InitPreCase;
		NozzleCases = InitNozzleCases;
		RestBalls = InitRestBalls;
		TimeSpent = InitTimeSpent;
	}

};

//노즐 선택
void F_InitializeCombination(vector<vector<int>> &CombinationVectors, vector<int> Balls, vector<int> NozzleSelection, int index, int count)
{
	if (count == 4)
	{
		vector<int> RestBalls = Balls;

		for (int j= 0; j<4; j++)
		{
			RestBalls[NozzleSelection[j]]--;

			if (RestBalls[NozzleSelection[j]] < 0)
			{
				return;
			}
		}

		CombinationVectors.push_back(NozzleSelection);
		return;
	}

	for(int i=index; i<6; i++)
	{
		NozzleSelection[count] = i;

		F_InitializeCombination(CombinationVectors, Balls, NozzleSelection, i, count+1);
	}
}

////노즐로 공 한 번 빼기
//vector<int> F_CalculateRestball(vector<vector<int>>& CombinationVectors, vector<int> Balls)
//{
//	return 
//}


int main()
{
	//공 개수 초기화
	vector<int> Balls(6);
	for (int i = 0; i < 6; i++)
	{
		cin >> Balls[i];
	}

	vector<vector<int>> CombinationVectors;

	S_NozzleBall Head(nullptr, CombinationVectors, Balls, 0);

	vector<int> NozzleSelection(4);

	F_InitializeCombination(CombinationVectors, Balls, NozzleSelection, 0, 0);

	
	
	for (const auto& comb : CombinationVectors) {
		for (int nozzle : comb) {
			cout << nozzle << " ";
		}
		cout << endl;
	}
	
	return 0;
}