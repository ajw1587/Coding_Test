#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

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

struct Edge {
	int v1;
	int v2;
	int val;
	Edge(int a, int b, int c)
	{
		v1 = a;
		v2 = b;
		val = c;
	}
};

//vector<int> unf(10001, 0);
int V = 9, E = 12, res = 0;
vector<Edge> edge;
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

bool cmp(vector<int> a, vector<int> b)
{
	if (a[0] != b[0]) return a[0] < b[0];
	else return a[1] < b[1];
}

// 가중치를 오름차순 정렬
bool cmp2(Edge a, Edge b)
{
	return a.val < b.val;
}

int Find(int a)
{
	if (a == unf[a]) return a;
	else return unf[a] = Find(unf[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

vector<int> unf(V + 1, 0);

int No78()
{
	system_clock::time_point start = system_clock::now();

	for (int i = 0; i < dis.size(); i++)
	{
		edge.push_back(Edge(dis[i][0], dis[i][1], dis[i][2]));
	}

	for (int i = 0; i <= V; i++)
	{
		unf[i] = i;
	}

	sort(edge.begin(), edge.end(), cmp2);

	for (int i = 0; i < E; i++)
	{
		int fa = Find(edge[i].v1);
		int fb = Find(edge[i].v2);
		if (fa != fb)
		{
			res += edge[i].val;
			Union(fa, fb);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No78();

	return 0;
}