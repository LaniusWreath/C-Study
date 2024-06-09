#include "iostream"
#include "vector"
#include "algorithm"
#include "memory"

using namespace std;

int MaxNozzleNumber = 4;
int MaxBallNumber = 6;
char NozzleNames[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
bool IsNozzleballFinished = false;

struct S_NozzleBall
{
	S_NozzleBall* ParentNode;

	vector<vector<int>> RegacyNozzle;
	vector<int> CalculatedBalls;

	vector<int> CalculatedCount;
	int CalculatedTime = 0;
	bool IsFinished = false;

	S_NozzleBall(S_NozzleBall* Parent)
	{
		ParentNode = Parent;
	}

	void F_InitializeCombination(vector<vector<int>>& CombinationVectors, vector<int> PreBalls, vector<int> NozzleSelection = {}, int index = 0, int count = 0)
	{
		int SelectBall;
		if (count == MaxNozzleNumber || all_of(PreBalls.begin(), PreBalls.end(), [](int i) {return i == 0; }))
		{
			//CombinationVectors
			CombinationVectors.push_back(NozzleSelection);
			return;
		}

		for (int i = index; i < MaxBallNumber; i++)
		{
			if (PreBalls[i] > 0)
			{
				SelectBall = i;
				PreBalls[i]--;

				NozzleSelection.push_back(SelectBall);
				F_InitializeCombination(CombinationVectors, PreBalls, NozzleSelection, i, count + 1);
				NozzleSelection.pop_back();

				PreBalls[i]++;
			}
		}
	}

	vector<int> F_PutOutBalls(const vector<int>& RegacyBalls, const vector<int>& NozzleSelection)
	{
		vector<int>NozzleMembers;
		for (int const& Nozzle : NozzleSelection)
		{
			if (count(NozzleMembers.begin(), NozzleMembers.end(), Nozzle) == 0)
			{
				NozzleMembers.push_back(Nozzle);
			}
		}

		vector<int> BallPool = RegacyBalls;
		bool IsStop = false;
		int CalCount = 0;

		while (true)
		{
			for (int i = 0; i < NozzleSelection.size(); i++)
			{
				BallPool[NozzleSelection[i]]--;
			}
			for (int j = 0; j < NozzleMembers.size(); j++)
			{
				if (BallPool[NozzleMembers[j]] <= 0)
				{
					IsStop = true;
					BallPool[NozzleMembers[j]] = 0;
				}
			}
			CalCount++;
			CalculatedTime += 2;

			if (IsStop)
			{
				break;
			}
		}

		CalculatedCount.push_back(CalCount);
		return BallPool;
	}


	void AddRegacyTime(const int& RegacyTime)
	{
		CalculatedTime += RegacyTime;
	}

	void InitializeRegacyNozzle(const vector<vector<int>>& ParentNozzle, const vector<int>& ParentCalculatedCount)
	{
		this->CalculatedCount = ParentCalculatedCount;
		this->RegacyNozzle = ParentNozzle;
	}

	void PrintStatus()
	{
		cout << "노즐 조합: ";
		for (int i = 0; i < RegacyNozzle.size(); i++)
		{
			cout << "[ ";
			for (const int& Nozzle : RegacyNozzle[i])
			{
				cout << NozzleNames[Nozzle] << " ";
			}
			cout << "] " << CalculatedCount[i] << "회 ";
		}

		cout << endl;

		cout << "잔여 공 개수: ";
		for (const int& Ball : CalculatedBalls)
		{
			cout << Ball << " ";
		}
		cout << endl;

		cout << "소요 시간: " << CalculatedTime << endl << endl;
	}

	bool CheckEnd()
	{
		for (const int& Ball : CalculatedBalls)
		{
			if (Ball > 0)
			{
				return false;
			}
		}

		return true;
	}
};

//Create&Initialize ChildNode
vector<S_NozzleBall*> F_CreateChildNodes(S_NozzleBall* NozzleBallPtr, const vector<int>& PreBalls)
{
	vector<vector<int>> CombinationVectors;
	NozzleBallPtr->F_InitializeCombination(CombinationVectors, PreBalls);

	vector<S_NozzleBall*> ChildNodeVectors;

	for (int i = 0; i < CombinationVectors.size(); i++)
	{
		S_NozzleBall* ChildNode = new S_NozzleBall(NozzleBallPtr);
		ChildNodeVectors.push_back(ChildNode);

		//Initialize Child Node RegacyNozzle
		ChildNode->InitializeRegacyNozzle(NozzleBallPtr->RegacyNozzle, NozzleBallPtr->CalculatedCount);

		//Initialize Head Next
		if (NozzleBallPtr->RegacyNozzle.size() == 0)
		{
			ChildNode->RegacyNozzle.push_back(CombinationVectors[i]);
		}

		//Add Current Nozzle, SwitchTime
		else
		{
			if (ChildNode->RegacyNozzle.back() != CombinationVectors[i])
			{
				ChildNode->RegacyNozzle.push_back(CombinationVectors[i]);
				ChildNode->CalculatedTime += 5;
			}
		}

		//Add Child Node Regacy Time
		ChildNode->AddRegacyTime(NozzleBallPtr->CalculatedTime);

		//Initialize Child Node CalculatedBalls 
		ChildNode->CalculatedBalls = ChildNode->F_PutOutBalls(NozzleBallPtr->CalculatedBalls, CombinationVectors[i]);

		ChildNode->PrintStatus();

		if (ChildNode->CheckEnd())
		{
			ChildNode->IsFinished = true;
		}
	}

	return ChildNodeVectors;
}

void F_ExcuteNozzleBall()
{
	int Count = 1;

	//Initialize Head Ball
	vector<int> BallInput(MaxBallNumber);
	for (int i = 0; i < MaxBallNumber; i++)
	{
		cin >> BallInput[i];
	}

	//Initialize Head
	S_NozzleBall* Head = new S_NozzleBall(nullptr);
	vector<vector<int>> HeadCombinationVectors;
	Head->RegacyNozzle = vector<vector<int>>();
	Head->CalculatedBalls = BallInput;


	cout << endl << "< " << Count << " 번째 조합을 계산 중입니다 >" << endl;
	Count++;

	vector<S_NozzleBall*>CurrentChildNodeVector = F_CreateChildNodes(Head, Head->CalculatedBalls);
	vector<S_NozzleBall*>NextChildNodeVector;
	vector<S_NozzleBall>BestNozzles;

	while (!IsNozzleballFinished)
	{
		cout << "< " << Count << "번째 조합을 계산 중입니다 >" << endl;

		for (S_NozzleBall* CurrentNode : CurrentChildNodeVector)
		{
			vector<S_NozzleBall*> TempChildNodeVector = F_CreateChildNodes(CurrentNode, CurrentNode->CalculatedBalls);
			for (S_NozzleBall* TempNode : TempChildNodeVector)
			{
				if (TempNode->IsFinished == true)
				{
					BestNozzles.push_back(*TempNode);
					IsNozzleballFinished = true;
				}
				NextChildNodeVector.push_back(TempNode);
			}
		}

		for (S_NozzleBall* CurrentNode : CurrentChildNodeVector)
		{
			delete CurrentNode;
		}

		CurrentChildNodeVector = NextChildNodeVector;
		NextChildNodeVector.clear();
	}

	cout << endl << "< 가장 효율적인 조합 및 노즐 변경 순서 리스트 >" << endl;

	for (S_NozzleBall Nozzle : BestNozzles)
	{
		Nozzle.PrintStatus();
	}

	cout << endl << "< 가장 효율적인 대표 조합 및 노즐 변경 대표 순서 >" << endl;

	BestNozzles[0].PrintStatus();

}


int main()
{
	F_ExcuteNozzleBall();

	return 0;
}