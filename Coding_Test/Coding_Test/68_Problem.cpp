#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 최소 비용 (DFS : 가중치 방향그래프 인접리스트
int N = 5, M = 8, dis = 2147000000;
vector<int> ch(30, 0);
vector<vector<int>> info =
{ {1, 2, 12},
{1, 3, 6},
{1, 4, 10},
{2, 3, 2},
{2, 5, 2},
{3, 4, 3},
{4, 2, 2},
{4, 5, 5} };

vector<pair<int, int>> map[30];

void DFS(int n, int temp)
{
	if (n == N)
	{
		dis = (dis > temp) ? temp : dis;
		return;
	}
	else
	{
		ch[n] = 1;
		for (int i = 0; i < map[n].size(); i++)
		{
			if (ch[map[n][i].first] == 0)
			{
				DFS(map[n][i].first, temp + map[n][i].second);
			}
		}
		ch[n] = 0;
	}
}

int No68()
{
	system_clock::time_point start = system_clock::now();

	for (int i = 0; i < info.size(); i++)
	{
		map[info[i][0]].push_back(make_pair(info[i][1], info[i][2]));
	}

	int temp = 0;
	DFS(1, temp);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No68();

	return 0;
}