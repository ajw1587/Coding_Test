#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 버블 정렬
int No34()
{
	system_clock::time_point start = system_clock::now();

	vector<int> points = { 80, 96, 75, 82, 96, 92, 100 };
	int temp, size = points.size();

	for (int j = 0; j < size - 1; j++)
	{
		for (int i = 0; i < size - j - 1; i++)
		{
			if (points[i] > points[i + 1])
			{
				temp = points[i];
				points[i] = points[i + 1];
				points[i + 1] = temp;
			}
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No34();
//
//	return 0;
//}