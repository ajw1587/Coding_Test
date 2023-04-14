#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �ƹ氡���� Ÿ�ϸ�
// https://school.programmers.co.kr/learn/courses/30/lessons/181186?language=cpp
// �̰͵� �𸣰ڴ�...
int No()
{
	system_clock::time_point start = system_clock::now();

	int n = 3;
	int answer = 0;
	vector<int> res(n, 0);
	res[0] = 1;
	res[1] = 3;
	res[2] = 10;

	for (int i = 3; i < n; i++)
	{
		res[i] = res[i - 1] + res[i - 2] * 2;
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