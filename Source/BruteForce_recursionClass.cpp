
//����
//ī���뿡�� ���� �α� �ִ� ���� ������ ��Ģ�� ����� ����.ī���� ���� 21�� ���� �ʴ� �ѵ� ������, ī���� ���� �ִ��� ũ�� ����� �����̴�.������ ī���븶�� �پ��� ������ �ִ�.
//
//�ѱ� �ְ��� ���� ��� �������� ���ο� ���� ��Ģ�� ����� ���, â���̿� �����Ϸ��� �Ѵ�.
//
//������ ������ ���迡�� �� ī�忡�� ���� ������ ���� �ִ�.�� ����, ������ N���� ī�带 ��� ���ڰ� ���̵��� �ٴڿ� ���´�.�׷� �Ŀ� ������ ���� M�� ũ�� ��ģ��.
//
//���� �÷��̾�� ���ѵ� �ð� �ȿ� N���� ī�� �߿��� 3���� ī�带 ���� �Ѵ�.���� ���� �����̱� ������, �÷��̾ �� ī���� ���� M�� ���� �����鼭 M�� �ִ��� ������ ������ �Ѵ�.
//
//N���� ī�忡 ���� �ִ� ���ڰ� �־����� ��, M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ���� ����Ͻÿ�.
//
//�Է�
//ù° �ٿ� ī���� ���� N(3 �� N �� 100)�� M(10 �� M �� 300, 000)�� �־�����.��° �ٿ��� ī�忡 ���� �ִ� ���� �־�����, �� ���� 100, 000�� ���� �ʴ� ���� �����̴�.
//
//���� M�� ���� �ʴ� ī�� 3���� ã�� �� �ִ� ��츸 �Է����� �־�����.
//
//���
//ù° �ٿ� M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ����Ѵ�.


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

		if (selectNumbers.size() == 3)
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
		int currentSumMax = 0, currentSum = 0;
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

			if (currentSum >= currentSumMax && currentSum <= M)
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
	BlackJack blackjack = BlackJack(n, m);

	blackjack.initializeVector();
	blackjack.PickNumber(0);
	int result = blackjack.SelectMaxNumber();

	cout << result;
	return 0;
}