#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// N×N 크기의 도시지도가 있습니다.
// 도시지도는 1×1크기의 격자칸으로 이루어져 있습니다.
// 각 격자칸에는 0은 빈칸, 1은 집, 2는 피자집으로 표현됩니다.
// 각 격자칸은 좌표(행번호, 열 번호)로 표현됩니다.
// 행번호는 1번부터 N번까지이고, 열 번호도 1부터 N까지입니다.
// 도시에는 각 집마다 “피자배달거리”가 았는데 각 집의 피자배달거리는 해당 집과 도시의
// 존재하는 피자집들과의 거리 중 최소값을 해당 집의 “피자배달거리”라고 한다.
// 집과 피자집의 피자배달거리는 | x1 - x2 | +| y1 - y2 | 이다.
// (1, 2)에 있는 집과 (2, 3)에 있는 피자집과의 피자 배달 거리는 |1-2| + |2-3| = 2가 된다.
// 도시 시장은 도시에 있는 피자집 중 M개만 살리고 나머지는 보조금을 주고 폐업시키려고 합니다.
// 도시의 피자배달거리가 최소가 되는 M개의 피자집을 선택하려고 합니다.
// 도시의 피자 배달 거리는 각 집들의 피자 배달 거리를 합한 것을 말합니다.

// 0은 빈칸, 1은 집, 2는 피자집으로 표현
// 4 4
// 0 1 2 0
// 1 0 2 1
// 0 2 1 2
// 2 0 1 2

int GetDis(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

void DFS(int idx, int S, vector<int> &res, vector<pair<int,int>> pizzas, vector<pair<int, int>> homes)
{
	if (idx == 4)
	{
		int sum = 0;
		for (int i = 0; i < homes.size(); i++)
		{
			int x1 = homes[i].first;
			int y1 = homes[i].second;
			for (int j = 0; j < res.size(); j++)
			{
				int x2 = pizzas[res[j]].first;
				int y2 = pizzas[res[j]].second;
			}
		}
	}
	else
	{
		for (int i = S; i < pizzas.size(); i++)
		{
			res[idx] = i;
			DFS(idx + 1, i + 1, res, pizzas, homes);
		}
	}
}

int No86()
{
	system_clock::time_point start = system_clock::now();

	int N = 4, M = 4;
	vector<vector<int>> map =
	{ {0, 1, 2, 0},
	{1, 0, 2, 1},
	{0, 2, 1, 2},
	{2, 0, 1, 2} };

	vector<pair<int, int>> pizzas;
	vector<pair<int, int>> homes;
	vector<int> res(M, 0);

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == 1)		// house
			{
				homes.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2)	// pizza
			{
				pizzas.push_back(make_pair(i, j));
			}
		}
	}

	DFS(0, 0, res, pizzas, homes);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No86();

	return 0;
}