#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 라이언킹 심바
// N×N 크기의 정글에 토끼 M마리와 어린 사자 심바가 있다.
// 정글은 1×1 크기의 격자로 이루어져 있다.
// 각 격자칸에는 토끼 1한마리가 있거나 또는 없을 수 있다.
// 어린 사자 심바는 주어진 정글에서 토끼를 잡아먹고 덩치를 키워 
// 삼촌 스카에게 복수를 하러 갈 예정이다.
// 
// 1) 더 이상 먹을 수 있는 토끼가 정글에 없다면 이제 심바는 삼촌 스카에게 복수하러 갈 수 있다.
// 2) 먹을 수 있는 토끼가 딱 한마리라면, 그 토끼를 먹으러 간다.
// 3) 먹을 수 있는 토끼가 2마리 이상이면, 거리가 가장 가까운 토끼를 먹으러 간다.
// ① 거리는 심바가 있는 칸에서 먹으려고 하는 토끼가 있는 칸으로 이동할 때,
//		지나야하는 칸의 개수의 최소값이다.
// ② 가장 가까운 토끼가 많으면, 그 중 가장 위쪽에 있는 토끼, 그러한 토끼가 여러 마리라면,
//		가장 왼쪽에 있는 토끼를 잡아먹는다.
// 심바는 자신의 몸 크기와 같은 마리수 만큼 잡아먹으면 몸의 크기가 1증가한다. 

struct Lion
{
	int x, y;
	int my_size, ate;
	void sizeUP()
	{
		ate = 0;
		my_size++;
	}
};

struct State
{
	int x, y;
	int dis;
	bool operator<(const State b) const
	{
		if (dis != b.dis) return dis > b.dis;
		else
		{
			if (x == b.x) return y > b.y;
			else return x > b.x;
		}
	}

	State(int a, int b, int d)
	{
		x = a;
		y = b;
		dis = d;
	}
};

int No90()
{
	system_clock::time_point start = system_clock::now();

	int N = 3;
	vector<vector<int>> map =
	{{ 0, 1, 3 },
	{ 1, 9, 1 },
	{ 0, 1, 1 }};

	vector<vector<int>> ch_map(N, vector<int>(N, 0));

	// 상하좌우
	vector<int> dx = { 0, 0, -1, 1 };
	vector<int> dy = { -1, 1, 0, 0 };

	// 심바 위치 찾아주기
	Lion simba;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 9)
			{
				simba.x = j;
				simba.y = i;
				simba.ate = 0;
				simba.my_size = 2;
				map[i][j] = 0;
			}
		}
	}

	// 토끼 먹기
	int res = 0;
	priority_queue<State> Q;
	Q.push(State(simba.x, simba.y, 0));
	while (!Q.empty())
	{
		State tmp = Q.top();
		Q.pop();
		int x = tmp.x;
		int y = tmp.y;
		int dis = tmp.dis;
		if (map[x][y] != 0 && map[x][y] < simba.my_size)
		{
			simba.x = x;
			simba.y = y;
			simba.ate++;
			if (simba.my_size <= simba.ate) simba.sizeUP();
			map[x][y] = 0;
			while (!Q.empty()) Q.pop();
			for (int i = 0; i < ch_map.size(); i++)
			{
				for (int j = 0; j < ch_map.size(); j++)
				{
					ch_map[i][j] = 0;
				}
			}

			res = tmp.dis;
		}

		for (int i = 0; i < dx.size(); i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || yy < 0 || xx >= N || yy >= N || ch_map[xx][yy] == 1) continue;

			ch_map[xx][yy] = 1;
			Q.push(State(xx, yy, dis + 1));
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No90();

	return 0;
}