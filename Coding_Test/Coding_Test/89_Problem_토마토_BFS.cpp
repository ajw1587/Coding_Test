#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 
// 아직 익지 않은 토마토들도 있을 수 있다.
// 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은
// 토마토의 영향을 받아 익게 된다.
// 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다.
// 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 
// 토마토가 혼자 저절로 익는 경우는 없다고 가정한다.
// 현수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
// M : 상자의 가로 칸 수, N : 상자의 세로 칸 수
// 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, -1은 토마토가 들어있지 않은 칸
int No89()
{
	system_clock::time_point start = system_clock::now();

	int M = 6, N = 4;
	vector<vector<int>> map =
	{ {0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1} };

	// 상하좌우
	vector<int> dx = { 0, 0, -1, 1 };
	vector<int> dy = { -1, 1, 0, 0 };

	// 익은 토마토 위치 찾아주기
	// 익은 토마토가 여러개 있을 수 있으니
	vector<pair<int, int>> tomatos;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1)
			{
				tomatos.push_back(make_pair(i, j));
			}
		}
	}

	// queue
	queue<pair<int, int>> q;
	
	// 처음 익은 토마토 위치 다 넣어주기
	for (int i = 0; i < tomatos.size(); i++)
	{
		q.push(make_pair(tomatos[i].first, tomatos[i].second));
	}

	// 확인하기
	int day = 0;
	while (!q.empty())
	{
		int q_size = q.size();
		for (int i = 0; i < q_size; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < dx.size(); j++)
			{
				int xx = x + dx[j];
				int yy = y + dy[j];
				if (xx < 0 || yy < 0 || xx >= N || yy >= M) continue;
				if (map[xx][yy] == 0)
				{
					map[xx][yy] = 1;
					q.push(make_pair(xx, yy));
				}
			}
		}
		day++;
	}

	cout << day-- << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No89();

	return 0;
}