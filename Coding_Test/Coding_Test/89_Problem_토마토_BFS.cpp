#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// â�� �����Ǵ� �丶��� �߿��� �� ���� �͵� ������, 
// ���� ���� ���� �丶��鵵 ���� �� �ִ�.
// ���� �� �Ϸ簡 ������, ���� �丶����� ������ ���� �ִ� ���� ���� �丶����� ����
// �丶���� ������ �޾� �Ͱ� �ȴ�.
// �ϳ��� �丶���� ������ ���� ����, ������, ��, �� �� ���⿡ �ִ� �丶�並 �ǹ��Ѵ�.
// �밢�� ���⿡ �ִ� �丶��鿡�Դ� ������ ���� ���ϸ�, 
// �丶�䰡 ȥ�� ������ �ʹ� ���� ���ٰ� �����Ѵ�.
// ������ â�� ������ �丶����� ��ĥ�� ������ �� �Ͱ� �Ǵ���, �� �ּ� �ϼ��� �˰� �;� �Ѵ�.
// M : ������ ���� ĭ ��, N : ������ ���� ĭ ��
// ���� 1�� ���� �丶��, ���� 0�� ���� ���� �丶��, -1�� �丶�䰡 ������� ���� ĭ
int No89()
{
	system_clock::time_point start = system_clock::now();

	int M = 6, N = 4;
	vector<vector<int>> map =
	{ {0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 1} };

	// �����¿�
	vector<int> dx = { 0, 0, -1, 1 };
	vector<int> dy = { -1, 1, 0, 0 };

	// ���� �丶�� ��ġ ã���ֱ�
	// ���� �丶�䰡 ������ ���� �� ������
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
	
	// ó�� ���� �丶�� ��ġ �� �־��ֱ�
	for (int i = 0; i < tomatos.size(); i++)
	{
		q.push(make_pair(tomatos[i].first, tomatos[i].second));
	}

	// Ȯ���ϱ�
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No89();

	return 0;
}