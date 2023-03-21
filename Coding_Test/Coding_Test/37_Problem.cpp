#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 카카오 캐시 문제 변형
// LRU 알고리즘을 따른다. 가장 오랫동안 사용하지 않은 것을 제거.
// ex) 2, 3, 1, 6, 7 (맨 앞이 가장 최근에 쓰인 작업)
// 1. Cache Miss : 해야할 작업이 캐시에 없는 상태
//				   5가 들어오면 5가 제일 앞에 위치 5, 2, 3, 1, 6
// 2. Cache Hit : 해야할 작업이 캐시에 있는 상태
//				   3번 작업을 한다면 3, 5, 2, 1, 6
// 캐시 크기가 주어지고, 비어있는 상태에서 N개의 작업을 처리한다면 캐시메모리의 상태는?
int No37()
{
	system_clock::time_point start = system_clock::now();

	vector<int> input_array = { 1, 2, 3, 2, 6, 2, 3, 5, 7 };
	vector<int> c(5, 0);
	int input = -1, size = 9;
	int	temp = -1, idx = -1;
	
	for (int i = 0; i < size; i++)
	{
		input = input_array[i];

		idx = -1;
		for (int j = 0; j < c.size(); j++) if (c[j] == input) idx = j;

		if (idx == -1)
		{
			for (int k = c.size() - 1; k >= 1; k--) c[k] = c[k - 1];
		}
		else
		{
			for (int k = idx; k >= 1; k--) c[k] = c[k - 1];
		}
		c[0] = input;
	}


	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No37();
//
//	return 0;
//}