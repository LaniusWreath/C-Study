#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {

	int N, M, i, j, k, Array[101] = {0};

	cin >> N >> M;

	for (int trials = 0; trials < M; trials++)
	{
		cin >> i >> j >> k;

		for (int number = i; number < j + 1; number++)
		{
			Array[number] = k;
		}
	}

	for (int current = 1; current < N+1; current++)
	{
		cout << Array[current] << " ";
	}

	return 0;
}
