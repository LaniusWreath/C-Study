#include "iostream"
#include "algorithm"
#include "cmath"
#include "vector"

//�� ���� �־����� ��, �࿡ ������ ���簢���� ����� ���ؼ� �ʿ��� �� ��° ���� ã�� ���α׷��� �ۼ��Ͻÿ�.
//=>�� �� �ԷµǴ� ���� ����, ���� ���� ��ȯ
int findSquarePoint(std::initializer_list<int> values)
{
	std::vector<int> vec;

	for (const int& val : values)
	{
		auto it = std::find(vec.begin(), vec.end(), val);
		if (it != vec.end()) {
			vec.erase(it);
		}
		else {
			vec.push_back(val);
		}
	}

	return vec[0];
}

int main()
{
	int x1, x2, x3, y1, y2, y3, resultX, resultY;

	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	resultX = findSquarePoint({ x1, x2, x3 });
	resultY = findSquarePoint({ y1, y2, y3 });

	std::cout << resultX << " " << resultY;
	return 0;
}
