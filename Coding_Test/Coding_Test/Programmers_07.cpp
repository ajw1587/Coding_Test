#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 광물 캐기
// https://school.programmers.co.kr/learn/courses/30/lessons/172927
int No()
{
	system_clock::time_point start = system_clock::now();

	// picks = [dia, iron, stone]
	vector<int> picks = { 1, 3, 2 };
	vector<string> minerals = { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };
	vector<vector<int>> save;
	vector<int> tmp;

	

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