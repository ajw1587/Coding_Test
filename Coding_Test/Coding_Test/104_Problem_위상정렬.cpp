#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 위상정렬
// 위상정렬은 어떤 일을 하는 순서를 찾는 알고리즘입니다.
// 각각의 일의 선후관계가 복잡하게 얽혀있을 때 각각 일의 선후관계를 유지하면서 전체 일의
// 순서를 짜는 알고리즘입니다.
// 만약 아래와 같은 일의 순서를 각각 지키면서 전체 일의 순서를 정한다면
// 1 4 -> 1번일을 하고 난 후 4번일을 해야한다.
int No104()
{
	system_clock::time_point start = system_clock::now();

	int N = 6, M = 6;
	vector<vector<int>> info =
	{ { 1, 4 },
	{ 5, 4 },
	{ 4, 3 },
	{ 2, 5 },
	{ 2, 3 },
	{ 6, 2 } };

	// 사용하기 위해 필요한 선행 조건 횟수 구해주기
	vector<int> degree(N + 1, 0);
	for (int i = 0; i < info.size(); i++)
	{
		int start = info[i][0];
		int end = info[i][1];
		degree[end]++;
	}

	// info 정리해주기
	vector<vector<int>> new_info(N + 1);
	for (int i = 0; i < info.size(); i++)
	{
		new_info[info[i][0]].push_back(info[i][1]);
	}

	// 선행 조건 횟수가 0인 부분 Q에 넣어주기
	queue<int> Q;
	for (int i = 1; i < degree.size(); i++)
	{
		if (degree[i] == 0) Q.push(i);
	}

	// 하나씩 꺼내서 조건 횟수 차감하기
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		cout << now << " ";
		for (int i = 0; i < new_info[now].size(); i++)
		{
			degree[new_info[now][i]]--;
			if (degree[new_info[now][i]] == 0) Q.push(new_info[now][i]);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No104();

	return 0;
}