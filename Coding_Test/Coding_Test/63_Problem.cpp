#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 인접행렬
// 정점의 개수 : 6, 간선의 개수 : 9
// 1 2 7
// 1 3 4
// 2 1 2
// 2 3 5
// 2 5 5
// 3 4 5
// 4 2 2
// 4 5 5
// 6 4 5
int No63()
{
	system_clock::time_point start = system_clock::now();

	int node = 6, line = 9;
	vector<vector<int>> map(node + 1, vector<int>(node + 1, 0));
	vector<vector<int>> info = 
	{ {1, 2, 7},
	  {1, 3, 4},
	  {2, 1, 2},
	  {2, 3, 5},
	  {2, 5, 5},
	  {3, 4, 5},
	  {4, 2, 2},
	  {4, 5, 5},
	  {6, 4, 5} };

	for (int i = 0; i < info.size(); i++)
	{
		map[info[i][0]][info[i][1]] = info[i][2];
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No63();

	return 0;
}