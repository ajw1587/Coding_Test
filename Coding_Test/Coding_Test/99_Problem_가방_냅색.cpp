#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���� ���� (���� �˰���)
// �ְ� 17kg�� ���Ը� ������ �� �ִ� ������ �ִ�.
// �׸��� ���� 3kg, 4kg, 7kg, 8kg, 9kg�� ���Ը� ���� 5������ ������ �ִ�.
// �� �������� ��ġ�� ���� 4, 5, 10, 11, 13�̴�.
// �� ������ ���濡 ��µ� 17kg�� ���� �����鼭 �ִ��� ��ġ�� �ǵ��� �Ϸ��� ��� ��ƾ� �ұ��?
// �� ������ ������ ������ ������ ����.
// �� ������ ������ ���� �� ���濡 ���� �� �ִٴ� ���Դϴ�

int N = 4, kg = 11;
int res_tmp = -1;

void My_DFS(int weight, int value, vector<pair<int, int>> info)
{
	for (int i = 0; i < info.size(); i++)
	{
		if (weight + info[i].first > 11)
		{
			res_tmp = (value > res_tmp) ? value : res_tmp;
			return;
		}
		else My_DFS(weight + info[i].first, value + info[i].second, info);
	}
}

int No99()
{
	system_clock::time_point start = system_clock::now();

	vector<pair<int, int>> info =
	{{ 5, 12 },
	{ 3, 8 },
	{ 6, 14 },
	{ 4, 8 }};

	My_DFS(0, 0, info);

	//////////////////////////////////////////////////////////////////////////
	// ���� �˰���
	vector<int> dy(11 + 1, 0);
	for (int i = 0; i < info.size(); i++)
	{
		int w = info[i].first;
		int v = info[i].second;
		for (int j = w; j < 11 + 1; j++)
		{
			dy[j] = max(dy[j], dy[j - w] + v);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No99();

	return 0;
}