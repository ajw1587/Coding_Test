#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �̷� Ž�� (DFS)
// �ڿ��� N�� �־����� 7x7 ������ �̷θ� Ż���ϴ� ����� �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ������� ������ (1, 1) ��ǥ�̰�, Ż�� �������� (7, 7) ��ǥ�̴�.
// �������� 1�� ���̰�, 0�� ����̴�.
// ���� �¿�θ� �����δ�.

int N = 7, cnt = 0;
vector<vector<int>> map, ch(N, vector<int>(N, 0));

// �����¿� (0, 1, 2, 3)
vector<int> di = { -1, 1, 0, 0 };
vector<int> dj = { 0, 0, -1, 1 };

// ������ 6, 6
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No65();

	return 0;
}