#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using namespace chrono;

// 원더랜드(Kruskal MST 알고리즘 : Union, Find 활용)
// 모든 도시를 연결하면서 최소의 유지비용이 들도록 도로를 선택하고
// 나머지 도로는 폐쇄한다.
// 어떤 도로는 도로를 유지보수하면 재정에 도움이 되는 도로도 존재한다.
// 재정에 도움이 되는 도로는 비용을 음수로 표현했다.
// V : 도시의 개수, E : 도로의 개수
// A와 B의 유지비용이 C인 도로로 연결
// 
// 모든 도시를 연결하면서 드는 최소비용을 출력하시오.
// 

int V = 9, E = 12, res = 0;
vector<vector<int>> dis =
{ {1, 2, 12},
	{2, 3, 10},
	{7, 8, 35},
	{2, 8, 17},
	{2, 9, 8},
	{3, 4, 18},
	{1, 9, 25},
	{3, 7, 55},
	{4, 5, 44},
	{5, 6, 60},
	{5, 7, 38},
	{8, 9, 15} };

struct Edge {
	int v1, v2, weight;
	Edge(int a, int b, int c)
	{
		v1 = a;
		v2 = b;
		weight = c;
	}
};

bool cmp(Edge a, Edge b)
{
	return a.weight < b.weight;
}

vector<int> ch(V + 1);

int Find(int a)
{
	if (ch[a] == a) return a;
	else return ch[a] = Find(ch[a]);
}

void Union(int a, int b)
{
	int fa = Find(a);
	int fb = Find(b);
	if (fa != fb) ch[a] = fb;
}

int My_No79()	// Kruskal 복습
{
	system_clock::time_point start = system_clock::now();

	// dis 정보 Edge에 담아주기
	vector<Edge> edge;
	for (int i = 0; i < E; i++)
	{
		edge.push_back(Edge(dis[i][0], dis[i][1], dis[i][2]));
	}

	// Edge Weight 기준으로 정렬하기
	sort(edge.begin(), edge.end(), cmp);

	// ch 노드정보 채워주기
	for (int i = 0; i < ch.size(); i++)
	{
		ch[i] = i;
	}

	// Find, Union 해주기
	int res = 0;
	for (int i = 0; i < E; i++)
	{
		int fa = Find(edge[i].v1);
		int fb = Find(edge[i].v2);
		if (fa != fb)
		{
			res += edge[i].weight;
			Union(fa, fb);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int No79()	// priority_queue
{
	system_clock::time_point start = system_clock::now();

	vector<vector<int>> info =
	{ {1, 2, 12},
		{2, 3, 10},
		{7, 8, 35},
		{2, 8, 17},
		{2, 9, 8},
		{3, 4, 18},
		{1, 9, 25},
		{3, 7, 55},
		{4, 5, 44},
		{5, 6, 60},
		{5, 7, 38},
		{8, 9, 15} };

	vector<vector<pair<int, int>>> iv(10);
	
	// info vector에 정보 넣어주기
	for (int i = 0; i < info.size(); i++)
	{
		iv[info[i][0]].push_back(make_pair(info[i][1], info[i][2]));
	}

	// check 만들어주기
	vector<bool> check(10, 0);

	// 진행해주기
	priority_queue<pair<int, int>> pq;
	while (!pq.empty())
	{

	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	My_No79();
	No79();

	return 0;
}