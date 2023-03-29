#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using namespace chrono;

// ��������(Kruskal MST �˰��� : Union, Find Ȱ��)
// ��� ���ø� �����ϸ鼭 �ּ��� ��������� �鵵�� ���θ� �����ϰ�
// ������ ���δ� ����Ѵ�.
// � ���δ� ���θ� ���������ϸ� ������ ������ �Ǵ� ���ε� �����Ѵ�.
// ������ ������ �Ǵ� ���δ� ����� ������ ǥ���ߴ�.
// V : ������ ����, E : ������ ����
// A�� B�� ��������� C�� ���η� ����
// 
// ��� ���ø� �����ϸ鼭 ��� �ּҺ���� ����Ͻÿ�.
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

int My_No79()	// Kruskal ����
{
	system_clock::time_point start = system_clock::now();

	// dis ���� Edge�� ����ֱ�
	vector<Edge> edge;
	for (int i = 0; i < E; i++)
	{
		edge.push_back(Edge(dis[i][0], dis[i][1], dis[i][2]));
	}

	// Edge Weight �������� �����ϱ�
	sort(edge.begin(), edge.end(), cmp);

	// ch ������� ä���ֱ�
	for (int i = 0; i < ch.size(); i++)
	{
		ch[i] = i;
	}

	// Find, Union ���ֱ�
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
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
	
	// info vector�� ���� �־��ֱ�
	for (int i = 0; i < info.size(); i++)
	{
		iv[info[i][0]].push_back(make_pair(info[i][1], info[i][2]));
	}

	// check ������ֱ�
	vector<bool> check(10, 0);

	// �������ֱ�
	priority_queue<pair<int, int>> pq;
	while (!pq.empty())
	{

	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	My_No79();
	No79();

	return 0;
}