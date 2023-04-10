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

struct Edge
{
	int start, end, weight;

	Edge(int a, int b, int w)
	{
		start = a;
		end = b;
		weight = w;
	}

	bool operator<(const Edge b) const
	{
		return weight > b.weight;
	}
};

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

	priority_queue<Edge> info;
	for (int i = 0; i < map.size(); i++)
	{
		info.push(Edge(map[i][0], map[i][1], map[i][2]));
	}

	for (int i = 0; i < map.size(); i++)
	{
		cout << info.top().weight << endl;
		info.pop();
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