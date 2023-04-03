#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 7*7 격자판 미로를 탈출하는 최단경로의 경로수를 출력하는 프로그램을 작성하세요.
// 경로수는 출발점에서 도착점까지 가는데 이동한 횟수를 의미한다.
// 출발점은 격자의(1, 1) 좌표이고, 탈출 도착점은(7, 7)좌표이다.
// 격자판의 1은 벽이고, 0은 도로이다.
// 격자판의 움직임은 상하좌우로만 움직인다.
int No88()
{
	system_clock::time_point start = system_clock::now();

	// 출발점은 0, 0
	// 도착점은 6, 6
	vector<vector<int>> map =
	{ {0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 1, 0, 0, 0},
		{1, 1, 0, 1, 0, 1, 1},
		{1, 1, 0, 1, 0, 0, 0},
		{1, 0, 0, 0, 1, 0, 0},
		{1, 0, 1, 0, 0, 0, 0} };

	// 상하좌우
	vector<int> dx = { 0, 0, -1, 1 };
	vector<int> dy = { -1, 1, 0, 0 };

	// queue
	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < dx.size(); k++)
		{
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (xx < 0 || xx >= 7 || yy < 0 || yy >= 7) continue;
			if (map[xx][yy] == 0)
			{
				map[xx][yy] = map[x][y] + 1;
				q.push(make_pair(xx, yy));
			}
		}
	}
	cout << map[6][6] << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No88();

	return 0;
}