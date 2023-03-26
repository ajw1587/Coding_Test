#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 경로 탐색 (DFS)
// 총 가지수 출력

int N = 5, M = 9;
int cnt = 0;
vector<int> ch(N + 1, 0);
vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));

void DFS(int n)
{
	if (n == N)
	{
		cnt++;
		return;
	}
	else
	{
		for (int i = 1; i < map[i].size(); i++)
		{
			if (map[n][i] == 1 && ch[i] == 0)
			{
				ch[i] = 1;
				DFS(i);
				ch[i] = 0;
			}
		}
	}
}

int No64()
{
	system_clock::time_point start = system_clock::now();
	ch[1] = 1;
	vector<vector<int>> info = 
	{ {1, 2},
	{ 1, 3 },
	{ 1, 4 },
	{ 2, 1 },
	{ 2, 3 },
	{ 2, 5 },
	{ 3, 4 },
	{ 4, 2 },
	{ 4, 5 }};

	for (int i = 0; i < info.size(); i++)
	{
		map[info[i][0]][info[i][1]] = 1;
	}

	DFS(1);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No64();

	return 0;
}