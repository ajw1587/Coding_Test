#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �� ���
// https://school.programmers.co.kr/learn/courses/30/lessons/140107
int No()
{
	system_clock::time_point start = system_clock::now();

	//int k = 1, d = 5;
	int k = 2, d = 4;

	for (int i = 0; i <= d; i++)
	{

	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No();

	return 0;
}