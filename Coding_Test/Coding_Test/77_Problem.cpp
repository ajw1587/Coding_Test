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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No77();

	return 0;
}