#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 다익스트라 알고리즘
// 아래의 가중치 방향그래프에서 1번 정점에서 모든 정점으로의 최소 거리비용을 출력하시오.
// 경로가 없으면 Impossible를 출력하시오.
// N : 정점의 수, M : 간선의 수

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

	// info 정리해주기
	vector<vector<Edge>> ev(N + 1);
	int i;
	for (i = 0; i < info.size(); i++)
	{
		ev[info[i][0]].push_back(Edge(info[i][1], info[i][2]));
	}

	// check list, priority_queue
	vector<int> ch(N + 1, 2147000000);
	priority_queue<Edge> pq;

	// 경로 찾아주기
	// 시작점은 0 (ch[1] = 0)
	ch[1] = 0;
	pq.push(Edge(1, 0));
	while (!pq.empty())
	{
		// 현재 위치 및 가중치
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
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No80();

	return 0;
}