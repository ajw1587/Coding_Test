#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using namespace chrono;

// 최대 수입 스케쥴
// 현수는 유명한 강연자이다. 
// N개의 기업에서 강연 요청을 해왔다. 
// 각 기업은 D일 안에 와서 강연을 해 주면 M만큼의 강연료를 주기로 했다.
// 각 기업이 요청한 D와 M를 바탕으로 가장 많을 돈을 벌 수 있도록 강연 스케쥴을 짜야 한다.
// 단 강연의 특성상 현수는 하루에 하나의 기업에서만 강연을 할 수 있다.
//

bool cmp(const pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second) return a.first > b.first;
	else return a.second > b.second;
}

int No75()
{
	system_clock::time_point start = system_clock::now();

	int N = 6, res = 0;
	vector<pair<int, int>> teach =
	{ {50, 2},
	{20, 1},
	{40, 2},
	{60, 3},
	{30, 3},
	{30, 1} };

	cout << teach[0].first << teach[0].second << endl;

	sort(teach.begin(), teach.end(), cmp);

	priority_queue<int> pQ;
	int i = 0;
	for (int j = 3; j >= 1; j--)
	{
		for (; i < teach.size(); i++)
		{
			if (teach[i].second < j) break;
			pQ.push(teach[i].first);
		}

		if (!pQ.empty())
		{
			res += pQ.top();
			pQ.pop();
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No75();

	return 0;
}