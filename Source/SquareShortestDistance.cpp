#include "iostream"
#include "algorithm"
#include "cmath"

//���簢���� ��輱���� �Ÿ��� �ּڰ�

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

//std::initializer_list<T> : ���� ���� �� �߰�ȣ�� ���� �޼��忡 �����ϴµ� ���� Ÿ��, values
//<algorithm> - std::min_element(ó��, ��) : ���� ���� ���� �� �� ��� ����Ű�� �ݺ��� ��ȯ