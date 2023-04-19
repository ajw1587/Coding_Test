#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;
using namespace chrono;

// 점 찍기
// https://school.programmers.co.kr/learn/courses/30/lessons/140107
int No()
{
	system_clock::time_point start = system_clock::now();

	//int k = 1, d = 5;
	int k = 2, d = 4;
	long long answer = 0;

	double tmp = 0;
	for (int i = 0; i <= d; i += k)
	{
		tmp = 0;
		tmp = sqrt(pow(d, 2) - pow(i, 2));

		answer += ((int)tmp / k + 1);
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No();

	return 0;
}