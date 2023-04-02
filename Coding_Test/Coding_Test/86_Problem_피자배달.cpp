#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// N��N ũ���� ���������� �ֽ��ϴ�.
// ���������� 1��1ũ���� ����ĭ���� �̷���� �ֽ��ϴ�.
// �� ����ĭ���� 0�� ��ĭ, 1�� ��, 2�� ���������� ǥ���˴ϴ�.
// �� ����ĭ�� ��ǥ(���ȣ, �� ��ȣ)�� ǥ���˴ϴ�.
// ���ȣ�� 1������ N�������̰�, �� ��ȣ�� 1���� N�����Դϴ�.
// ���ÿ��� �� ������ �����ڹ�ްŸ����� �Ҵµ� �� ���� ���ڹ�ްŸ��� �ش� ���� ������
// �����ϴ� ����������� �Ÿ� �� �ּҰ��� �ش� ���� �����ڹ�ްŸ������ �Ѵ�.
// ���� �������� ���ڹ�ްŸ��� | x1 - x2 | +| y1 - y2 | �̴�.
// (1, 2)�� �ִ� ���� (2, 3)�� �ִ� ���������� ���� ��� �Ÿ��� |1-2| + |2-3| = 2�� �ȴ�.
// ���� ������ ���ÿ� �ִ� ������ �� M���� �츮�� �������� �������� �ְ� �����Ű���� �մϴ�.
// ������ ���ڹ�ްŸ��� �ּҰ� �Ǵ� M���� �������� �����Ϸ��� �մϴ�.
// ������ ���� ��� �Ÿ��� �� ������ ���� ��� �Ÿ��� ���� ���� ���մϴ�.

// 0�� ��ĭ, 1�� ��, 2�� ���������� ǥ��
// 4 4
// 0 1 2 0
// 1 0 2 1
// 0 2 1 2
// 2 0 1 2

int GetDis(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

void DFS(int L, int s, vector<int> &ch, vector<pair<int, int>> pizzas, vector<pair<int, int>> homes)
{
	if (L == 4)
	{
		for (int i = 0; i < ch.size(); i++)
		{
			cout << ch[i] << ' ';
		}
		cout << endl;
	}
	else
	{
		for (int i = s; i < pizzas.size(); i++)
		{
			ch[L] = i;
			DFS(L + 1, i + 1, ch, pizzas, homes);
		}
	}
}

vector<bool> ch(6, 0);

void test_DFS(int idx, int s, vector<int>& res, vector<int> test)
{
	if (idx == 5)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << res[i] << ' ';
		}
		cout << endl;
	}
	else
	{
		for (int i = s; i < test.size(); i++)
		{
			res[idx] = test[i];
			test_DFS(idx + 1, i + 1, res, test);
		}
		//for (int i = s; i < test.size(); i++)
		//{
		//	if (ch[i] == 0)
		//	{
		//		ch[i] = 1;
		//		res[idx] = test[i];
		//		test_DFS(idx + 1, 0, res, test);
		//		ch[i] = 0;
		//	}
		//}
	}
}

int No86()
{
	system_clock::time_point start = system_clock::now();

	int N = 4, M = 4;
	vector<vector<int>> map =
	{ {0, 1, 2, 0},
	{1, 0, 2, 1},
	{0, 2, 1, 2},
	{2, 0, 1, 2} };

	vector<pair<int, int>> pizzas;
	vector<pair<int, int>> homes;
	vector<int> ch(M, 0);

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			if (map[i][j] == 1)		// house
			{
				homes.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2)	// pizza
			{
				pizzas.push_back(make_pair(i, j));
			}
		}
	}

	DFS(0, 0, ch, pizzas, homes);
	cout << endl;
	cout << endl;

	////////////////////////////////////////////////////////////
	vector<int> test(6, 0);
	vector<int> res(5, 0);
	for (int i = 0; i < test.size(); i++)
	{
		test[i] = i + 1;
	}

	test_DFS(0, 0, res, test);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No86();

	return 0;
}