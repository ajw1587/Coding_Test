#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 플로이드 워샬
// N개의 도시가 주어지고, 각 도시들을 연결하는 도로와 해당 도로를 통행하는
// 비용이 주어질 때 모든 도시에서 모든 도시로 이동하는데
// 쓰이는 비용의 최소값을 구하는 프로그램을 작성하세요.
// 왜케 아프냐...

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
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No102();

	return 0;
}