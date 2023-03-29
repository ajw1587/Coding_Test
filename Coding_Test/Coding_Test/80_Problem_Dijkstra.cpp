#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// ���ͽ�Ʈ�� �˰���
// �Ʒ��� ����ġ ����׷������� 1�� �������� ��� ���������� �ּ� �Ÿ������ ����Ͻÿ�.
// ��ΰ� ������ Impossible�� ����Ͻÿ�.
// N : ������ ��, M : ������ ��

struct Edge
{
	int e, weight;
	Edge(int a, int b)
	{
		e = a;
		weight = b;
	}
	bool operator<(const Edge b) const
	{
		return weight > b.weight;
	}
};

int No80()
{
	system_clock::time_point start = system_clock::now();

	// Input
	int N = 6, M = 9;
	vector<vector<int>> info =
	{{ 1, 2, 12 },
	{ 1, 3, 4 },
	{ 2, 1, 2 },
	{ 2, 3, 5 },
	{ 2, 5, 5 },
	{ 3, 4, 5 },
	{ 4, 2, 2 },
	{ 4, 5, 5 },
	{ 6, 4, 5 }};

	// info �������ֱ�
	vector<vector<Edge>> ev(N + 1);
	int i;
	for (i = 0; i < info.size(); i++)
	{
		ev[info[i][0]].push_back(Edge(info[i][1], info[i][2]));
	}

	// check list, priority_queue
	vector<int> ch(N + 1, 2147000000);
	priority_queue<Edge> pq;

	// ��� ã���ֱ�
	// �������� 0 (ch[1] = 0)
	ch[1] = 0;
	pq.push(Edge(1, 0));
	while (!pq.empty())
	{
		// ���� ��ġ �� ����ġ
		int cur = pq.top().e;
		int weight = pq.top().weight;
		pq.pop();
		
		if (ch[cur] < weight) continue;
		for (i = 0; i < ev[cur].size(); i++)
		{
			int next = ev[cur][i].e;
			int n_weight = ev[cur][i].weight + weight;
			if (ch[next] > n_weight)
			{
				ch[next] = n_weight;
				pq.push(Edge(next, n_weight));
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
	No80();

	return 0;
}