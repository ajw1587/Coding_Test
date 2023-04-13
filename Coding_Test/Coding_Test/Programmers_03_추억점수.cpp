#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;
using namespace chrono;

// 추억점수
// https://school.programmers.co.kr/learn/courses/30/lessons/176963
int No()
{
	system_clock::time_point start = system_clock::now();

	vector<string> name = { "may", "kein", "kain", "radi" };
	vector<int> point = { 5, 10, 1, 3 };
	vector<vector<string>> ar =
	{ {"may", "kein", "kain", "radi"},
	{"may", "kein", "brin", "deny"},
	{"kon", "kain", "may", "coni"} };

	unordered_map<string, int> name_point;
	for (int i = 0; i < name.size(); i++)
	{
		name_point.insert(make_pair(name[i], point[i]));
	}

	vector<int> answer;
	for (int i = 0; i < ar.size(); i++)
	{
		int res = 0;
		for (int j = 0; j < ar[i].size(); j++)
		{
			res += name_point[ar[i][j]];
		}
		answer.push_back(res);
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