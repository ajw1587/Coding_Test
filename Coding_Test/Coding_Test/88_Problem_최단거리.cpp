#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 7*7 ������ �̷θ� Ż���ϴ� �ִܰ���� ��μ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
// ��μ��� ��������� ���������� ���µ� �̵��� Ƚ���� �ǹ��Ѵ�.
// ������� ������(1, 1) ��ǥ�̰�, Ż�� ��������(7, 7)��ǥ�̴�.
// �������� 1�� ���̰�, 0�� �����̴�.
// �������� �������� �����¿�θ� �����δ�.
int No88()
{
	system_clock::time_point start = system_clock::now();

	// ������� 0, 0
	// �������� 6, 6
	vector<vector<int>> map =
	{ {0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 1, 1, 1, 0},
		{0, 0, 0, 1, 0, 0, 0},
		{1, 1, 0, 1, 0, 1, 1},
		{1, 1, 0, 1, 0, 0, 0},
		{1, 0, 0, 0, 1, 0, 0},
		{1, 0, 1, 0, 0, 0, 0} };

	// �����¿�
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No88();

	return 0;
}