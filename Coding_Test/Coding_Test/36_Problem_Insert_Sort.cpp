#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 삽입 정렬
int No36()
{
	system_clock::time_point start = system_clock::now();

	vector<int> v = { 11, 7, 5, 6, 10, 9 };
	int temp = -1, j = 0;

	for (int i = 1; i < v.size(); i++)
	{
		temp = v[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (temp < v[j])
			{
				v[j + 1] = v[j];
			}
			else break;
		}
		v[j + 1] = temp;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No36();
//
//	return 0;
//}