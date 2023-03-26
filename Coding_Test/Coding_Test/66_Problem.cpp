#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 경로 탐색 (DFS : 인접리스트 방법)
// 총 가지수 출력
vector<int> map[30];
vector<int> ch(30, 0);
int cnt = 0;

void DFS(int n)
{
	if (n == 5) cnt++;
	else
	{
		ch[n] = 1;
		for (int i = 0; i < map[n].size(); i++)
		{
			if (ch[map[n][i]] != 1)
			{
				DFS(map[n][i]);
			}
		}
		ch[n] = 0;
	}
}

int No66()
{
	system_clock::time_point start = system_clock::now();

	vector<vector<int>> info =
	{ {1, 2},
	{ 1, 3 },
	{ 1, 4 },
	{ 2, 1 },
	{ 2, 3 },
	{ 2, 5 },
	{ 3, 4 },
	{ 4, 2 },
	{ 4, 5 } };

	for (int i = 0; i < info.size(); i++)
	{
		map[info[i][0]].push_back(info[i][1]);
	}

	DFS(1);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No66();

	return 0;
}