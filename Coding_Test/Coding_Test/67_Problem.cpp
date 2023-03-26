#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 최소 비용
int N = 5, M = 8, dis = 2147000000;
vector<vector<int>> info =
{ {1, 2, 12},
{1, 3, 6},
{1, 4, 10},
{2, 3, 2},
{2, 5, 2},
{3, 4, 3},
{4, 2, 2},
{4, 5, 5} };
vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));
vector<int> ch(N + 1, 0);

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
		for (int i = 1; i < map[n].size(); i++)
		{
			if (ch[i] == 0 && map[n][i] > 0)
			{
				DFS(i, temp + map[n][i]);
			}
		}
		ch[n] = 0;
	}
}

int No67()
{
	system_clock::time_point start = system_clock::now();

	for (int i = 0; i < info.size(); i++)
	{
		map[info[i][0]][info[i][1]] = info[i][2];
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
	No67();

	return 0;
}