#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;
using namespace chrono;

// �� �� ������ ������
// https://school.programmers.co.kr/learn/courses/30/lessons/181187
// �̰� �𸣰ڳ�;;
int No()
{
	system_clock::time_point start = system_clock::now();

	int r1 = 2, r2 = 3;
	vector<pair<int, int>> points;
	
	int answer = 0;
	for (int i = 1; i <= r2; i++)
	{
		int h2 = floor(sqrt(pow(r2, 2) - pow(i, 2)));
		cout << h2 << endl;
		answer += h2 + 1;
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