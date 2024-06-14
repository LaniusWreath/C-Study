#include "iostream"
#include "vector"
#include "algorithm"

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
	~S_NozzleBall()
	{

	}

	//Create Combination with Repetition
	void F_CreateCombinations(vector<vector<int>>& CombinationVectors, vector<int> PreBalls, vector<int> NozzleSelection = {}, int index = 0, int count = 0)
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
				F_CreateCombinations(CombinationVectors, PreBalls, NozzleSelection, i, count + 1);
				NozzleSelection.pop_back();

				PreBalls[i]++;
			}
		}
	}

	//Subtract Balls while Selected Members are Zero
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

	//Add Time from Parent Node
	void AddRegacyTime(const int& RegacyTime)
	{
		CalculatedTime += RegacyTime;
	}

	//Initialzie Parent Node Nozzle Vector
	void InitializeRegacyNozzle(const vector<vector<int>>& ParentNozzle, const vector<int>& ParentCalculatedCount)
	{
		this->CalculatedCount = ParentCalculatedCount;
		this->RegacyNozzle = ParentNozzle;
	}

	//Print Node Status
	void PrintStatus()
	{
		cout << "���� ����: ";
		for (int i = 0; i < RegacyNozzle.size(); i++)
		{
			cout << "[ ";
			for (const int& Nozzle : RegacyNozzle[i])
			{
				cout << NozzleNames[Nozzle] << " ";
			}
			cout << "] " << CalculatedCount[i] << "ȸ ";
		}

		cout << endl;

		cout << "�ܿ� �� ����: ";
		for (const int& Ball : CalculatedBalls)
		{
			cout << Ball << " ";
		}
		cout << endl;

		cout << "�ҿ� �ð�: " << CalculatedTime << endl << endl;
	}

	//Check if All Ball Members are zero
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
	NozzleBallPtr->F_CreateCombinations(CombinationVectors, PreBalls);
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

//Excute Program
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


	cout << endl << "< " << Count << " ��° ������ ��� ���Դϴ� >" << endl;
	Count++;

	vector<S_NozzleBall*>CurrentChildNodeVector = F_CreateChildNodes(Head, Head->CalculatedBalls);
	vector<S_NozzleBall*>NextChildNodeVector;
	S_NozzleBall BestNozzle = S_NozzleBall(nullptr);

	while (!IsNozzleballFinished)
	{
		cout << "< " << Count << "��° ������ ��� ���Դϴ� >" << endl;

		for (S_NozzleBall* CurrentNode : CurrentChildNodeVector)
		{
			vector<S_NozzleBall*> TempChildNodeVector = F_CreateChildNodes(CurrentNode, CurrentNode->CalculatedBalls);
			for (S_NozzleBall* TempNode : TempChildNodeVector)
			{
				if (TempNode->IsFinished == true)
				{
					BestNozzle = *TempNode;
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

		Count++;
	}
	
	for (S_NozzleBall* Node : CurrentChildNodeVector)
	{
		delete Node;
	}

	cout << endl << "< ���� ȿ������ ��ǥ ���� �� ���� ���� ��ǥ ���� >" << endl;

	BestNozzle.PrintStatus();

	delete Head;
}

int main()
{
	F_ExcuteNozzleBall();

	return 0;
}