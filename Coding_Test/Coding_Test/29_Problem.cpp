#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 자연수 N이 주어졌을때 1부터 N까지 3의 개수
int No29()
{
	system_clock::time_point start = system_clock::now();

	int N = 15, count = 0, tmp = 0;
	
	for (int i = 1; i <= N; i++)
	{
		tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 3) count++;
			tmp /= 10;
		}
	}
	cout << count << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No29();
//
//	return 0;
//}