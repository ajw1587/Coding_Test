#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 섬나라 아일랜드의 지도가 격자판의 정보로 주어집니다.
// 각 섬은 1로 표시되어 상하좌우와 대각선으로 연결되어 있으며, 0은 바다입니다.
// 섬나라 아일랜드에 몇 개의 섬이 있는지 구하는 프로그램을 작성하세요.
int No87()
{
	system_clock::time_point start = system_clock::now();

	int N = 7;
	vector<vector<int>> map =
	{ { 1, 1, 0, 0, 0, 1, 0 },
	{ 0, 1, 1, 0, 1, 1, 0 },
	{ 0, 1, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 1, 0, 1, 1 },
	{ 1, 1, 0, 1, 1, 0, 0 },
	{ 1, 0, 0, 0, 1, 0, 0 },
	{ 1, 0, 1, 0, 1, 0, 0 } };

	// 상하좌우 오위, 오아, 왼위, 왼아
	vector<int> dx = { 0, 0, -1, 1, 1, 1, -1, -1};
	vector<int> dy = { -1, 1, 0, 0, -1, 1, -1, 1};

	// check map
	vector<vector<bool>> ch_map(N, vector<bool>(N, 0));

	// queue
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0 || ch_map[i][j] == 1) continue;
			q.push(make_pair(i, j));
			ch_map[i][j] == 1;
			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int k = 0; k < dx.size(); k++)
				{
					int xx = x + dx[k];
					int yy = y + dy[k];
					if (xx < 0 || yy < 0 || xx >= N || yy >= N) continue;
					if (map[xx][yy] == 1 && ch_map[xx][yy] == 0)
					{
						ch_map[xx][yy] = 1;
						q.push(make_pair(xx, yy));
					}
				}
			}
			cnt++;
		}
	}
	cout << cnt << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No87();

	return 0;
}