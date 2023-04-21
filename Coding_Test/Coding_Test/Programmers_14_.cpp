#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 우박수열 정적분
// https://school.programmers.co.kr/learn/courses/30/lessons/134239

void DFS(int k, vector<int> &tmp)
{
	if (k == 1)
	{
		tmp.push_back(k);
		return;
	}
	else
	{
		tmp.push_back(k);
		if (k % 2 == 0)
		{
			DFS(k / 2, tmp);
		}
		else
		{
			DFS(k * 3 + 1, tmp);
		}
	}
}

int No()
{
	system_clock::time_point start = system_clock::now();

	vector<double> answer;

	int k = 5;
	vector<vector<int>> ranges =
	{ {0, 0}, {0, -1}, {2, -3}, {3, -3} };

	vector<int> graph;
	DFS(k, graph);
	vector<double> graph_area(graph.size() - 1, -1);

	for (int i = 0; i < ranges.size(); i++)
	{
		int rx1 = ranges[i][0];
		int rx2 = graph.size() - 1 + ranges[i][1];

		if (rx2 - rx1 < 0)
		{
			answer.push_back(-1.0);
		}
		else if (rx2 - rx1 == 0)
		{
			answer.push_back(0.0);
		}
		else  // gx2 - gx1 > 0
		{
			double tmp = 0;
			for (int j = rx1; j <= rx2 - 1; j++)
			{
				if (graph_area[j] == -1)
				{
					int gy1 = graph[j];
					int gy2 = graph[j + 1];

					double down = (gy1 > gy2) ? gy2 : gy1;
					double up = (gy1 > gy2) ? gy1 - gy2 : gy2 - gy1;

					graph_area[j] = down + up / 2;

					tmp += down;
					tmp += up / 2;
				}
				else
				{
					tmp += graph_area[j];
				}
			}
			answer.push_back(tmp);
		}

	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No();

	return 0;
}