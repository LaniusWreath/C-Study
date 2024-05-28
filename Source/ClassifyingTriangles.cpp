#include "iostream"
#include "array"
#include "string"

std::string ClassifyingTriangles(std::array<int, 3> values)
{
	std::array<std::string, 4> triangles = { "Equilateral", "Isosceles", "Scalene", "Error" };
	std::string result = "";

	if (values[0] and values[1] and values[2] == 60)
	{
		result = triangles[0];
	}
	else if (values[0] + values[1] + values[2] == 180)
	{
		if (values[0] != values[1] and values[0] != values[2] and values[1] != values[2])
		{
			result = triangles[2];
		}
		else
		{
			result = triangles[1];
		}
	}
	else
	{
		result = triangles[3];
	}

	return result;
}

int main()
{
	int a, b, c = 0;
	std::cin >> a >> b >> c;

	std::cout << ClassifyingTriangles({ a,b,c });

	return 0;
}
