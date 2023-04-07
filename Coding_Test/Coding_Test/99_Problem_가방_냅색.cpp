#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 가방 문제 (냅색 알고리즘)
// 최고 17kg의 무게를 저장할 수 있는 가방이 있다.
// 그리고 각각 3kg, 4kg, 7kg, 8kg, 9kg의 무게를 가진 5종류의 보석이 있다.
// 이 보석들의 가치는 각각 4, 5, 10, 11, 13이다.
// 이 보석을 가방에 담는데 17kg를 넘지 않으면서 최대의 가치가 되도록 하려면 어떻게 담아야 할까요?
// 각 종류별 보석의 개수는 무한이 많다.
// 한 종류의 보석을 여러 번 가방에 담을 수 있다는 뜻입니다

int N = 4, kg = 11;
int res_tmp = -1;

void My_DFS(int weight, int value, vector<pair<int, int>> info)
{
	for (int i = 0; i < info.size(); i++)
	{
		if (weight + info[i].first > 11)
		{
			res_tmp = (value > res_tmp) ? value : res_tmp;
			return;
		}
		else My_DFS(weight + info[i].first, value + info[i].second, info);
	}
}

int No99()
{
	system_clock::time_point start = system_clock::now();

	vector<pair<int, int>> info =
	{{ 5, 12 },
	{ 3, 8 },
	{ 6, 14 },
	{ 4, 8 }};

	My_DFS(0, 0, info);

	//////////////////////////////////////////////////////////////////////////
	// 냅색 알고리즘
	vector<int> dy(11 + 1, 0);
	for (int i = 0; i < info.size(); i++)
	{
		int w = info[i].first;
		int v = info[i].second;
		for (int j = w; j < 11 + 1; j++)
		{
			dy[j] = max(dy[j], dy[j - w] + v);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No99();

	return 0;
}