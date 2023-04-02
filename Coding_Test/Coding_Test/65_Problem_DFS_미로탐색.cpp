#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 미로 탐색 (DFS)
// 자연수 N이 주어지면 7x7 격자판 미로를 탈출하는 경로의 가지수를 출력하는 프로그램을 작성하시오.
// 출발점은 격자의 (1, 1) 좌표이고, 탈출 도착점은 (7, 7) 좌표이다.
// 격자판의 1은 벽이고, 0은 통로이다.
// 상하 좌우로만 움직인다.

int N = 7, cnt = 0;
vector<vector<int>> map, ch(N, vector<int>(N, 0));

// 상하좌우 (0, 1, 2, 3)
vector<int> di = { -1, 1, 0, 0 };
vector<int> dj = { 0, 0, -1, 1 };

// 정답은 6, 6
void My_DFS(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N)
	{
		return;
	}
	else
	{
		if (x == N - 1 && y == N - 1)
		{
			cnt++;
			return;
		}

		if (ch[x][y] == 0 && map[x][y] != 1)
		{
			ch[x][y] = 1;
			for (int i = 0; i < di.size(); i++)
			{
				My_DFS(x + di[i], y + dj[i]);
			}
			ch[x][y] = 0;
		}
	}
}

void DFS(int x, int y)
{
	if (x == 6 && y == 6)
	{
		cnt++;
		return;
	}
	else
	{
		for (int i = 0; i < di.size(); i++)
		{
			int xx = x + di[i];
			int yy = y + dj[i];
			if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
			if (map[xx][yy] == 0 && ch[xx][yy] == 0)
			{
				ch[xx][yy] = 1;
				DFS(xx, yy);
				ch[xx][yy] = 0;
			}
		}
	}
}

int No65()
{
	system_clock::time_point start = system_clock::now();

	map = 
	{ {0, 0, 0, 0, 0, 0, 0},
	{ 0, 1, 1, 1, 1, 1, 0 },
	{ 0, 0, 0, 1, 0, 0, 0 },
	{ 1, 1, 0, 1, 0, 1, 1 },
	{ 1, 1, 0, 0, 0, 0, 1 },
	{ 1, 1, 0, 1, 1, 0, 0 },
	{ 1, 0, 0, 0, 0, 0, 0 }};

	ch[0][0] = 1;
	DFS(0, 0);

	ch[0][0] = 0;
	My_DFS(0, 0);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No65();

	return 0;
}