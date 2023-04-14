#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

// 요격 시스템
// https://school.programmers.co.kr/learn/courses/30/lessons/181188

bool cmp(vector<int> a, vector<int> b)
{
	if (a[0] != b[0]) return a[0] < b[0];
	else return a[1] < b[1];
}

int No()
{
	system_clock::time_point start = system_clock::now();

	vector<vector<int>> targets =
	{ {4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4} };

	sort(targets.begin(), targets.end(), cmp);

	for (vector<int> t : targets)
	{
		cout << t[0] << " " << t[1] << endl;
	}

	int cnt = 1;
	int cur = 0;
	int next = 1;
	while (cur < targets.size() && next < targets.size())
	{
		if (targets[cur][1] > targets[next][0])
		{
			if (targets[cur][1] > targets[next][1])
				cur = next;
			next++;
		}
		else
		{
			cur = next;
			next++;
			cnt++;
		}
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