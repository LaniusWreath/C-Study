#include "iostream"
#include "algorithm"
#include "vector"

//점 n개를 둘러싸는 최소 크기의 사각형 넓이 구하기

template<typename T>
T FindMin(std::vector<T>& values) { //매개변수로 불러올 때 참조자로 불러오면 메모리 절약. (복사 -> 전달)
	return *std::min_element(values.begin(), values.end());
}

template<typename T>
T FindMax(std::vector<T>& values) {
	return *std::max_element(values.begin(), values.end());
}

int main()
{
	int n, cur_x, cur_y, height, width;
	std::vector<int> vec_x;
	std::vector<int> vec_y;

	std::cin >> n;

	//vector.reserve(n) : 벡터 크기 미리 예약 => 필요한 메모리만 미리 할당. 메모리 재할당 줄여 성능 향상
	vec_x.reserve(n);
	vec_y.reserve(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> cur_x >> cur_y;
		vec_x.push_back(cur_x);
		vec_y.push_back(cur_y);
	}

	width = FindMax(vec_x) - FindMin(vec_x);
	height = FindMax(vec_y) - FindMin(vec_y);

	std::cout << width * height;

	return 0;
}
