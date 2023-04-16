#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 광물 캐기
// https://school.programmers.co.kr/learn/courses/30/lessons/172927

vector<vector<int>> tired =
{
	{1, 1, 1},
	{5, 1, 1},
	{25, 5, 1}
};
//vector<int> picks = { 1, 3, 2 };
//vector<string> minerals = 
//{ "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };

//vector<int> picks = { 0, 1, 1 };
//vector<string> minerals =
//{ "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" };

vector<int> picks = { 1, 1, 1 };
vector<string> minerals =
{ "stone", "stone", "stone", "stone", "stone", "diamond", "diamond", "diamond", "diamond", "diamond", "stone", "stone", "stone", "stone" };
int rres = 2147000000;

void DFS(int m_idx, int res, int sum)
{
	if (m_idx >= minerals.size() || sum == 0)
	{
		rres = min(rres, res);
		cout << res << endl;
		return;
	}
	else
	{
		int idx, j;
		int tmp = 0;
		for (int i = 0; i < picks.size(); i++)
		{
			tmp = 0;
			if (picks[i] != 0)
			{
				for (j = 0; j < 5; j++)
				{
					if (m_idx + j >= minerals.size())
					{
						break;
					}
					else
					{
						if (minerals[m_idx + j] == "diamond") idx = 0;
						else if (minerals[m_idx + j] == "iron") idx = 1;
						else idx = 2;
						tmp += tired[i][idx];
					}
				}

				picks[i]--;
				DFS(m_idx + j, res + tmp, sum - 1);
				picks[i]++;
			}
		}
	}
}

int No()
{
	system_clock::time_point start = system_clock::now();
	
	// picks = [dia, iron, stone]
	//vector<int> picks = { 1, 3, 2 };
	//vector<string> minerals = { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };
	int answer = 0;
	int sum = 0;
	for (int i = 0; i < picks.size(); i++)
	{
		sum += picks[i];
	}
	DFS(0, 0, sum);

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