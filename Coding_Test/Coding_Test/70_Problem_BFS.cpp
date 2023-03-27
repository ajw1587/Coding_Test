#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 그래프 최단거리 (BFS)

int N = 6, M = 9;
vector<vector<int>> info =
{ {1, 3},
{1, 4},
{2, 1},
{2, 5},
{3, 4},
{4, 5},
{4, 6},
{6, 2},
{6, 5} };
vector<int> map[30];
vector<int> ch(N + 1, 0);
vector<int> dis(N + 1, 0);

int No70()
{
	system_clock::time_point start = system_clock::now();

	for (int i = 0; i < info.size(); i++)
	{
		map[info[i][0]].push_back(info[i][1]);
	}

	int x;
	queue<int> q;
	q.push(1);
	ch[1] = 1;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		for (int i = 0; i < map[x].size(); i++)
		{
			if (ch[map[x][i]] == 0)
			{
				ch[map[x][i]] = 1;
				q.push(map[x][i]);
				dis[map[x][i]] = dis[x] + 1;
			}
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No70();

	return 0;
}