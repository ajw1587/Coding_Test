#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 선택 정렬
// 인덱스 순서대로 가장 작은 값을 찾아준다.
int No32()
{
	system_clock::time_point start = system_clock::now();

	vector<int> test = { 13, 5, 11, 7, 23, 15 };
	int min = 99999, temp, idx;
	for (int i = 0; i < test.size()-1; i++)
	{
		idx = i;
		for (int j = i + 1; j < test.size(); j++)
		{
			if (test[idx] > test[j]) idx = j;
		}
		temp = test[i];
		test[i] = test[idx];
		test[idx] = temp;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No32();
//
//	return 0;
//}