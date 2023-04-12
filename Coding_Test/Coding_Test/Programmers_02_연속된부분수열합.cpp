#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 연속된 부분 수열의 합
// https://school.programmers.co.kr/learn/courses/30/lessons/178870
int No()
{
	system_clock::time_point start = system_clock::now();



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