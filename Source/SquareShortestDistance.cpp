#include "iostream"
#include "algorithm"
#include "cmath"

//직사각형의 경계선까지 거리의 최솟값

template<typename T>
T findMin(std::initializer_list<T> values) {
	return *std::min_element(values.begin(), values.end());
}

int main()
{
	int x, y, w, h, result;

	std::cin >> x >> y >> w >> h;

	result = findMin({ x, y, w - x, h - y });

	std::cout << result << "\n";
	return 0;
}

//std::initializer_list<T> : 여러 개의 값 중괄호로 묶어 메서드에 전달하는데 쓰는 타입, values
//<algorithm> - std::min_element(처음, 끝) : 범위 내의 가장 작 은 요소 가리키는 반복자 반환