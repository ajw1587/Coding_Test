#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// ���� ���� �˰���
// N���� ���ð� �־�����, 
// �� ���õ��� �����ϴ� ���ο� �ش� ���θ� �����ϴ� ����� �־��� �� 
// �� ���ÿ��� �ٸ� ���÷� �̵��ϴµ� ���̴� ����� �ּҰ��� ���ϴ� ���α׷��� �ۼ��ϼ���.
// N : ������ ��, M : ���μ�
// S : ���, cur : ����

struct Dij_Edge
{
	int cur, weight;
	Dij_Edge(int b, int w)
	{
		cur = b;
		weight = w;
	}

	bool operator<(const Dij_Edge b) const
	{
		return weight > b.weight;
	}
};

int Dijkstra_No81()
{
	system_clock::time_point start = system_clock::now();

	int N = 5, M = 7;
	int S = 1, E = 5;
	vector<vector<int>> info =
	{ { 1, 2, 5 },
	{ 1, 3, 4 },
	{ 2, 3, -3 },
	{ 2, 5, 13 },
	{ 3, 4, 5 },
	{ 4, 2, 3 },
	{ 4, 5, 7 } };
	
	// map ������ֱ�
	int i;
	vector<vector<Dij_Edge>> map(N + 1);
	for (i = 0; i < info.size(); i++)
	{
		map[info[i][0]].push_back(Dij_Edge(info[i][1], info[i][2]));
	}

	// dis_check, priority_queue ����
	vector<int> dis_check(N + 1, 2147000000);
	priority_queue<Dij_Edge> pq;
	bool flag = false;
	dis_check[S] = 0;
	pq.push(Dij_Edge(S, 0));
	while (!pq.empty())
	{
		int cur = pq.top().cur;
		int c_w = pq.top().weight;
		pq.pop();

		if (cur == E)
		{
			if (dis_check[cur] == 2147000000) flag = false;
			else flag = true;
			break;
		}

		if (dis_check[cur] < c_w) continue;

		for (i = 0; i < map[cur].size(); i++)
		{
			int next = map[cur][i].cur;
			int n_w = map[cur][i].weight + c_w;

			if (dis_check[next] > n_w)
			{
				dis_check[next] = n_w;
				pq.push(Dij_Edge(next, n_w));
			}
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////

struct Bell_Edge
{
	int s, e, val;
	Bell_Edge(int a, int b, int c)
	{
		s = a;
		e = b;
		c = val;
	}
};

int No81()
{
	system_clock::time_point start = system_clock::now();

	int N = 5, M = 7;
	int S = 1, E = 5;
	vector<vector<int>> info =
	{ { 1, 2, 5 },
	{ 1, 3, 4 },
	{ 2, 3, -3 },
	{ 2, 5, 13 },
	{ 3, 4, 5 },
	{ 4, 2, 3 },
	{ 4, 5, 7 } };

	// vector<Edge> ����� �ֱ�
	vector<Bell_Edge> Ed;
	for (int i = 0; i < info.size(); i++)
	{
		Ed.push_back(Bell_Edge(info[i][0], info[i][1], info[i][2]));
	}

	// dist
	vector<int> dist(101, 2147000000);
	
	// ����
	dist[S] = 0;
	for(int i = 1; i < )

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	Dijkstra_No81();
	No81();

	return 0;
}