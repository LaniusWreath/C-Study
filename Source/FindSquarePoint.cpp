#include "iostream"
#include "algorithm"
#include "cmath"
#include "vector"

//세 점이 주어졌을 때, 축에 평행한 직사각형을 만들기 위해서 필요한 네 번째 점을 찾는 프로그램을 작성하시오.
//=>두 번 입력되는 값을 제거, 남은 값을 반환
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
