#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;
using namespace chrono;

// 두 원 사이의 정수쌍
// https://school.programmers.co.kr/learn/courses/30/lessons/181187
// 이거 모르겠네;;
int No()
{
	system_clock::time_point start = system_clock::now();

	int r1 = 2, r2 = 3;
	vector<pair<int, int>> points;
	
	long long answer = 0;
	double r2y = 0, r1y = 0;
	int side = 0;
	for (int i = 1; i < r2; i++)
	{
		r2y = sqrt(pow(r2, 2) - pow(i, 2));

		if (r1 > i) r1y = sqrt(pow(r1, 2) - pow(i, 2));
		else r1y = 0;

		if (r1y - (int)r1y == 0 && r1y != 0)
			side++;

		answer += ((int)r2y - (int)r1y);
	}
	answer = (answer + side + r2 - r1 + 1) * 4;

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