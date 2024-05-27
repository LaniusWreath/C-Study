#include "iostream"
#include "algorithm"
#include "vector"

//�� n���� �ѷ��δ� �ּ� ũ���� �簢�� ���� ���ϱ�

template<typename T>
T FindMin(std::vector<T>& values) { //�Ű������� �ҷ��� �� �����ڷ� �ҷ����� �޸� ����. (���� -> ����)
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

	//vector.reserve(n) : ���� ũ�� �̸� ���� => �ʿ��� �޸𸮸� �̸� �Ҵ�. �޸� ���Ҵ� �ٿ� ���� ���
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
