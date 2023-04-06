#include <iostream>
#include <chrono>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
using namespace chrono;

// ���� ���� �� �ױ�
// �ظ��� ���簢���� ������ü �������� ����Ͽ� ž�� �װ��� �Ѵ�.
// ž�� ������ �� ���� �Ʒ����� ���� �����鼭 ����� ����.
// �Ʒ��� ������ �����ϸ鼭 ���� ���� ž�� ���� �� �ִ� ���α׷��� �ۼ��Ͻÿ�.
// 
// (����1)������ ȸ����ų �� ����.��, ������ �ظ����� ����� �� ����.
// (����2)�ظ��� ���̰� ���� ������ ������, ���� ���԰� ���� ������ ����.
// (����3)�������� ���̴� ���� ���� �ִ�.
// (����4)ž�� ���� �� �ظ��� ���� ���� ���� �ظ��� ���� ������ ���� �� ����.
// (����5)���԰� ���ſ� ������ ���԰� ������ ���� ���� ���� �� ����.
//
// ���� �ظ��� ����, ������ ���� �׸��� ���԰� ���ʴ�� ���� ������ �־�����.

struct my_block
{
	int area, height, weight;
	my_block(int a, int h, int w)
	{
		area = a;
		height = h;
		weight = w;
	}

	bool operator<(const my_block c) const
	{
		return area > c.area;
	}
};

int No96()
{
	system_clock::time_point start = system_clock::now();

	int N = 5;
	vector<int> res(N, 0);
	// ����, ����, ����
	vector<vector<int>> info =
	{{ 25, 3, 4 },
	{ 4, 4, 6 },
	{ 9, 2, 3 },
	{ 16, 2, 5 },
	{ 1, 5, 2 }};

	// ���� ���� �������� ����
	vector<my_block> list;
	for (int i = 0; i < N; i++)
	{
		list.push_back(my_block(info[i][0], info[i][1], info[i][2]));
	}
	sort(list.begin(), list.end());

	// ���� ���� �������ֱ�
	res[0] = list[0].height;
	for (int i = 1; i < res.size(); i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (list[i].weight < list[j].weight &&  res[i] < res[j] + list[i].height)
			{
				res[i] = res[j] + list[i].height;
			}
			else
			{
				res[i] = list[i].height;
			}
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No96();

	return 0;
}