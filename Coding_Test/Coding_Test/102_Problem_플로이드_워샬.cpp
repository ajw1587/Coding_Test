#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// �÷��̵� ����
// N���� ���ð� �־�����, �� ���õ��� �����ϴ� ���ο� �ش� ���θ� �����ϴ�
// ����� �־��� �� ��� ���ÿ��� ��� ���÷� �̵��ϴµ�
// ���̴� ����� �ּҰ��� ���ϴ� ���α׷��� �ۼ��ϼ���.
// ���� ������...

int No102()
{
	system_clock::time_point start = system_clock::now();

	int city = 5, load = 8;
	vector<vector<int>> map =
	{ { 1, 2, 6 },
	{ 1, 3, 3 },
	{ 3, 2, 2 },
	{ 2, 4, 1 },
	{ 2, 5, 13 },
	{ 3, 4, 5 },
	{ 4, 2, 3 },
	{ 4, 5, 7 } };

	vector<vector<int>> dis(city + 1, vector<int>(city + 1, 10000));
	for (int i = 0; i < map.size(); i++)
	{
		int s = map[i][0];
		int e = map[i][1];
		int v = map[i][2];
		dis[s][e] = v;
	}
	for (int i = 0; i < dis.size(); i++) dis[i][i] = 0;

	for (int k = 1; k <= city; k++)
	{
		for (int i = 1; i < dis.size(); i++)
		{
			for (int j = 1; j < dis[i].size(); j++)
			{
				if (dis[i][j] > dis[i][k] + dis[k][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
				}
				//dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	// ���
	for (int i = 1; i < dis.size(); i++)
	{
		for (int j = 1; j < dis[i].size(); j++)
		{
			if (dis[i][j] == 10000) cout << "M ";
			else cout << dis[i][j] << " ";
		}
		cout << endl;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No102();

	return 0;
}