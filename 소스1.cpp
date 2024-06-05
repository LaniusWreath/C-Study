#include "iostream"
#include "vector"
#include "algorithm"

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
	const S_NozzleBall* PreCase;
	int PreVectorIndex;
	bool IsLast;

	vector<S_NozzleBall*> ChildObjectsPtrVector;

	vector<vector<int>> CombinationVectors;
	vector<vector<int>> RestBalls;
	vector<int> TimeSpent;

	S_NozzleBall(S_NozzleBall* InitPreCase, const int& InitPreVectorIndex)
	{
		PreCase = InitPreCase;
		PreVectorIndex = InitPreVectorIndex;
	}
	~S_NozzleBall()
	{
		for (auto child : ChildObjectsPtrVector)
		{
			delete child;
		}
	}

	void F_InitializeCombination(const vector<int>& PreBalls, vector<int> NozzleSelection = vector<int>(4), int index = 0, int count = 0)
	{
		if (count == 4)
		{
			vector<int> Balls = PreBalls;
			for (int j = 0; j < 4; j++)
			{
				Balls[NozzleSelection[j]]--;
			}

			if (CheckEnd(Balls))
			{
				IsLast = true;
			}

			//RestBalls
			RestBalls.push_back(Balls);

			//CombinationVectors
			CombinationVectors.push_back(NozzleSelection);
			return;
		}
		for (int i = index; i < 6; i++)
		{
			NozzleSelection[count] = i;
			F_InitializeCombination(PreBalls, NozzleSelection, i, count + 1);
		}
	}

	void F_InitializeTimeSpent()
	{
		//Prevecter
		vector<int> PreVecter = PreCase->CombinationVectors[PreVectorIndex];

		//Initialize TimeSpent
		TimeSpent.resize(CombinationVectors.size(), 0);

		for (int i = 0; i < CombinationVectors.size(); i++)
		{
			//PreTime
			int PreTime = PreCase->TimeSpent[PreVectorIndex];

			//PutOut Time
			TimeSpent[i] = PreTime + 2;

			bool changed = false;

			for (int j = 0; j < 4; j++)
			{
				//NozzleChange Time
				if (CombinationVectors[i][j] != PreVecter[j])
				{
					changed = true;
				}
			}

			if (changed)
			{
				TimeSpent[i] += 5;
			}
		}
	}

	void Job(const int& i)
	{
		F_InitializeCombination(PreCase->RestBalls[PreVectorIndex]);
		F_InitializeTimeSpent();
	}

	void CreateAndInitializeChildObject()
	{
		for (int i = 0; i < CombinationVectors.size(); i++)
		{
			S_NozzleBall* CurrentChild = new S_NozzleBall(this, i);
			ChildObjectsPtrVector.push_back(CurrentChild);
			CurrentChild->Job(i);
		}
	}

	void CreateChildObject()
	{
		for (int i = 0; i < CombinationVectors.size(); i++)
		{
			S_NozzleBall* CurrentChild = new S_NozzleBall(this, i);
			ChildObjectsPtrVector.push_back(CurrentChild);
		}
	}

	vector<S_NozzleBall*> GetChildObjectPtrVector()
	{
		return ChildObjectsPtrVector;
	}

	bool GetIsEnd()
	{
		return IsLast;
	}

	bool CheckEnd(const vector<int>& Balls)
	{
		for (int i = 0; i < 6; i++)
		{
			if (Balls[i] > 0)
			{
				return false;
			}
		}
		return true;
	}
};

int main()
{
	//Initialize Head Ball
	vector<int> Balls(6);
	for (int i = 0; i < 6; i++)
	{
		cin >> Balls[i];
	}

	//Initialize Head
	S_NozzleBall* Head = new S_NozzleBall(nullptr, 0);
	Head->CreateChildObject();
	Head->F_InitializeCombination(Balls, vector<int>(4), 0, 0);
	Head->TimeSpent = vector<int>(Head->CombinationVectors.size(), 2);
	vector<S_NozzleBall*> PreObjectPtrVector = Head->GetChildObjectPtrVector();

	bool BreakLoop = false;
	vector<S_NozzleBall*> MinChildObjectPtrVector;
	vector<S_NozzleBall*> CurrentObjectPtrVector;

	while (!BreakLoop)
	{
		vector<S_NozzleBall*> NextObjectPtrVector;

		for (int i = 0; i < PreObjectPtrVector.size(); i++)
		{
			cout << i << " 번째 PreObjectPtrVector" << endl;

			PreObjectPtrVector[i]->CreateAndInitializeChildObject();
			CurrentObjectPtrVector = PreObjectPtrVector[i]->GetChildObjectPtrVector();

			//검증
			for (int j = 0; j < CurrentObjectPtrVector.size(); j++)
			{
				cout << j << "번째 검증 중" << endl;
				if (CurrentObjectPtrVector[j]->GetIsEnd())
				{
					BreakLoop = true;

					cout << CurrentObjectPtrVector[i] << " Has Min Nozzles " << endl;
					cout << " is Min Index " << endl;

					MinChildObjectPtrVector.push_back(CurrentObjectPtrVector[j]);
				}
				else
				{
					NextObjectPtrVector.push_back(CurrentObjectPtrVector[j]);
				}
			}
		}
		if (BreakLoop)
		{
			break;
		}

		PreObjectPtrVector = NextObjectPtrVector;
	}
	//	//PreChildObjectPtrVector = CurrentChildObjectPtrVector;
	//	//CurrentChildObjectPtrVector = CurrentChildObjectPtrVector[]

	//	if (BreakLoop)
	//	{
	//		break;
	//	}
	//}

	//for (int i = 0; i < Head->CombinationVectors.size(); i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//	{
	//		cout << Head->CombinationVectors[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//for (int i = 0; i < Next.CombinationVectors.size(); i++)
	//{
	//	cout << Next.TimeSpent[i];
	//}


	delete Head;

	return 0;
}