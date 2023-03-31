#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 벨만 포드 알고리즘
// N개의 도시가 주어지고, 
// 각 도시들을 연결하는 도로와 해당 도로를 통행하는 비용이 주어질 때 
// 한 도시에서 다른 도시로 이동하는데 쓰이는 비용의 최소값을 구하는 프로그램을 작성하세요.
// N : 도시의 수, M : 도로수
// S : 출발, cur : 도착

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
	
	// map 만들어주기
	int i;
	vector<vector<Dij_Edge>> map(N + 1);
	for (i = 0; i < info.size(); i++)
	{
		map[info[i][0]].push_back(Dij_Edge(info[i][1], info[i][2]));
	}

	// dis_check, priority_queue 진행
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
	cout << "소요 시간 : " << micro.count() << endl;
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
		val = c;
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
	{ 2, 3, -9 },
	{ 2, 5, 13 },
	{ 3, 4, 5 },
	{ 4, 2, 3 },
	{ 4, 5, 7 } };

	// vector<Edge> 만들어 주기 (간선 정보)
	vector<Bell_Edge> Ed;
	for (int i = 0; i < info.size(); i++)
	{
		Ed.push_back(Bell_Edge(info[i][0], info[i][1], info[i][2]));
	}

	// 거리 정보 만들어주기
	vector<vector<int>> l_info(N+1, vector<int>(N+1, 2147000000));

	int i = 0;
	l_info[0][1] = 0;
	for (i = 1; i < N; i++)
	{
		l_info[i][1] = 0;
		for (int j = 0; j < Ed.size(); j++)
		{
			int s = Ed[j].s;
			int e = Ed[j].e;
			int val = Ed[j].val;

			if (l_info[i - 1][s] == 2147000000) continue;

			if (l_info[i - 1][s] + val <= l_info[i - 1][e])
			{
				l_info[i][e] = l_info[i - 1][s] + val;
			}
		}
	}

	// 음의 사이클 검토
	for (int j = 0; j < Ed.size(); j++)
	{
		int s = Ed[j].s;
		int e = Ed[j].e;
		int val = Ed[j].val;

		if (l_info[i - 1][s] == 2147000000) continue;

		if (l_info[i - 1][s] + val <= l_info[i - 1][e])
		{
			cout << -1 << endl;
			exit(0);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	Dijkstra_No81();
	No81();

	return 0;
}