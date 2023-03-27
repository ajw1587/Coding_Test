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

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first) return a < b;
	else return a.second < b.second;
}

void DFS(int idx, int b, vector<bool> &ch, const vector<pair<int, int>> friends)
{
	if (friends[idx].second == b)
	{
		cout << "YES" << endl;
		return;
	}
	else
	{

	}
}

int No77()
{
	system_clock::time_point start = system_clock::now();

	int N = 9, M = 7;
	int a = 3, b = 8, idx = -1;
	vector<bool> ch(N, 0);
	vector<pair<int, int>> friends =
	{ {1, 2},
	{ 2, 3 },
	{ 3, 4 },
	{ 4, 5 },
	{ 6, 7 },
	{ 7, 8 },
	{ 8, 9 }};

	sort(friends.begin(), friends.end(), cmp);
	for (int i = 0; i < friends.size(); i++)
	{
		if (friends[i].first == a)
		{
			idx = i;
			break;
		}
	}

	DFS(idx, b, ch, friends);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No77();

	return 0;
}