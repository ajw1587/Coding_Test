#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// ���̾�ŷ �ɹ�
// N��N ũ���� ���ۿ� �䳢 M������ � ���� �ɹٰ� �ִ�.
// ������ 1��1 ũ���� ���ڷ� �̷���� �ִ�.
// �� ����ĭ���� �䳢 1�Ѹ����� �ְų� �Ǵ� ���� �� �ִ�.
// � ���� �ɹٴ� �־��� ���ۿ��� �䳢�� ��Ƹ԰� ��ġ�� Ű�� 
// ���� ��ī���� ������ �Ϸ� �� �����̴�.
// 
// 1) �� �̻� ���� �� �ִ� �䳢�� ���ۿ� ���ٸ� ���� �ɹٴ� ���� ��ī���� �����Ϸ� �� �� �ִ�.
// 2) ���� �� �ִ� �䳢�� �� �Ѹ������, �� �䳢�� ������ ����.
// 3) ���� �� �ִ� �䳢�� 2���� �̻��̸�, �Ÿ��� ���� ����� �䳢�� ������ ����.
// �� �Ÿ��� �ɹٰ� �ִ� ĭ���� �������� �ϴ� �䳢�� �ִ� ĭ���� �̵��� ��,
//		�������ϴ� ĭ�� ������ �ּҰ��̴�.
// �� ���� ����� �䳢�� ������, �� �� ���� ���ʿ� �ִ� �䳢, �׷��� �䳢�� ���� �������,
//		���� ���ʿ� �ִ� �䳢�� ��ƸԴ´�.
// �ɹٴ� �ڽ��� �� ũ��� ���� ������ ��ŭ ��Ƹ����� ���� ũ�Ⱑ 1�����Ѵ�. 

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

	// �����¿�
	vector<int> dx = { 0, 0, -1, 1 };
	vector<int> dy = { -1, 1, 0, 0 };

	// �ɹ� ��ġ ã���ֱ�
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

	// �䳢 �Ա�
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No90();

	return 0;
}