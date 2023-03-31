#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 자연수 N과 R이 주어지면 서로 다른 N개의 자연수 중 R개를 뽑아 일렬로
// 나열하는 프로그램을 작성하시오.

void DFS(int idx, vector<int> info, vector<bool> &ch, vector<int> &res)
{
	if (idx == 3)
	{
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << ' ';
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < info.size(); i++)
		{
			if (ch[i] == 0)
			{
				res[idx] = info[i];
				ch[i] = 1;
				DFS(idx + 1, info, ch, res);
				ch[i] = 0;
			}
		}
	}
}

int No82()
{
	system_clock::time_point start = system_clock::now();

	int N = 4, R = 3;
	vector<int> info = { 1, 3, 6, 7 };
	vector<bool> ch(N, 0);
	vector<int> res(3, 0);
	int idx = 0;

	DFS(idx, info, ch, res);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No82();

	return 0;
}