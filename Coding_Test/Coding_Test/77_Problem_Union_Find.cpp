#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

// 친구인가?
// 반 학생은 N명이다.
// 현수는 각 학생들의 친구관계를 알고 싶다.
// 모든 학생은 1부터 N까지 번호가 부여되어 있고,
// 현수에게는 각각 두 명의 학생은 친구 관계가 번호로 표현된 숫자쌍이 주어진다.
// 만약 (1, 2), (2, 3), (3, 4)의 숫자쌍이 주어지면
// 1번 학생과 2번 학생이 친구이고, 2번과 3번이 친구, 3번과 4번이 친구이다.
// 그리고 1번과 4번은 2번과 3번을 통해서 친구관계가 된다.
// 특정 두 명이 친구인지를 판별하는 프로그램을 작성하시오.
// 친구이면, YES
// 아니면, NO
//

bool flag = false;

void DFS(int a, int b, vector<bool> &ch, const vector<vector<int>> map)
{
	if (a == b)
	{
		flag = true;
		return;
	}
	else
	{
		ch[a] = 1;
		for (int i = 0; i < map[a].size(); i++)
		{
			if(ch[map[a][i]] == 0) DFS(map[a][i], b, ch, map);
		}
		ch[a] = 0;
	}
}

int My_No77()
{
	system_clock::time_point start = system_clock::now();

	int N = 9, M = 7;
	int a = 3, b = 8;
	vector<bool> ch(N, 0);
	vector<pair<int, int>> friends =
	{ {1, 2},
	{ 2, 3 },
	{ 3, 4 },
	{ 4, 5 },
	{ 6, 7 },
	{ 7, 8 },
	{ 8, 9 }};

	//vector<int> map[30];
	vector<vector<int>> map(10);

	for (int i = 0; i < friends.size(); i++)
	{
		map[friends[i].first].push_back(friends[i].second);
	}

	DFS(a, b, ch, map);

	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

vector<int> unf(1001);

int Find(int v)
{
	if (v == unf[v]) return v;
	else return unf[v] = Find(unf[v]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a != b) unf[a] = b;
}

int No77()
{
	system_clock::time_point start = system_clock::now();

	int N = 9, M = 7;
	int a = 3, b = 8;
	vector<bool> ch(N, 0);
	vector<pair<int, int>> friends =
	{ {1, 2},
	{ 2, 3 },
	{ 3, 4 },
	{ 4, 5 },
	{ 6, 7 },
	{ 7, 8 },
	{ 8, 9 } };

	for (int i = 1; i <= N; i++)
	{
		unf[i] = i;
	}

	for (int i = 0; i < friends.size(); i++)
	{
		Union(friends[i].first, friends[i].second);
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	My_No77();
	No77();

	return 0;
}