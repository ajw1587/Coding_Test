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

struct Edge
{
	int v2, weight;

	Edge(int b, int c)
	{
		v2 = b;
		weight = c;
	}

	bool operator<(const Edge &b)const
	{
		return weight > b.weight;
	}
};

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
		iv[info[i][1]].push_back(make_pair(info[i][0], info[i][2]));
	}

	// check ������ֱ�
	vector<bool> check(10, 0);

	// �������ֱ�
	int res = 0, cnt = 9;
	priority_queue<Edge> pq;
	pq.push(Edge(1, 0));
	while (!pq.empty())
	{
		Edge tmp = pq.top();
		pq.pop();
		int e = tmp.v2;
		int weight = tmp.weight;
		if (check[e] == 0 && cnt != 0)
		{
			check[e] = 1;
			cnt--;
			res += weight;
			for (int i = 0; i < iv[e].size(); i++)
			{
				pq.push(Edge(iv[e][i].first, iv[e][i].second));
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
	No79();

	return 0;
}