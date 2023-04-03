#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// ������ ���Ϸ����� ������ �������� ������ �־����ϴ�.
// �� ���� 1�� ǥ�õǾ� �����¿�� �밢������ ����Ǿ� ������, 0�� �ٴ��Դϴ�.
// ������ ���Ϸ��忡 �� ���� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��ϼ���.
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

	// �����¿� ����, ����, ����, �޾�
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No87();

	return 0;
}