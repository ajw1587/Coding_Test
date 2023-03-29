#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

// ģ���ΰ�?
// �� �л��� N���̴�.
// ������ �� �л����� ģ�����踦 �˰� �ʹ�.
// ��� �л��� 1���� N���� ��ȣ�� �ο��Ǿ� �ְ�,
// �������Դ� ���� �� ���� �л��� ģ�� ���谡 ��ȣ�� ǥ���� ���ڽ��� �־�����.
// ���� (1, 2), (2, 3), (3, 4)�� ���ڽ��� �־�����
// 1�� �л��� 2�� �л��� ģ���̰�, 2���� 3���� ģ��, 3���� 4���� ģ���̴�.
// �׸��� 1���� 4���� 2���� 3���� ���ؼ� ģ�����谡 �ȴ�.
// Ư�� �� ���� ģ�������� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ģ���̸�, YES
// �ƴϸ�, NO
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	My_No77();
	No77();

	return 0;
}