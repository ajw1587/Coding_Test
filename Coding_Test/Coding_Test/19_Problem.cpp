#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 한 줄에 앉은키 정보가 주어지면 뒷사람 모두의 시야를 가린다.
// 시야를 모두 가리는 사람의 수를 구하시오.
int No19()
{
	system_clock::time_point start = system_clock::now();

	int N = 10, max = -1, answer = 0;
	vector<int> height = { 56, 46, 55, 76, 65, 53, 52, 53, 55, 50 };

	for (int i = height.size()-1; i > -1; i--)
	{
		if (i == height.size() - 1)
		{
			max = height[i];
			continue;
		}

		if (height[i] > max)
		{
			max = height[i];
			answer++;
		}
	}

	cout << answer << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No19();
//
//	return 0;
//}