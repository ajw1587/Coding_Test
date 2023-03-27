#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using namespace chrono;

// �ִ� ���� ������
// ������ ������ �������̴�. 
// N���� ������� ���� ��û�� �ؿԴ�. 
// �� ����� D�� �ȿ� �ͼ� ������ �� �ָ� M��ŭ�� �����Ḧ �ֱ�� �ߴ�.
// �� ����� ��û�� D�� M�� �������� ���� ���� ���� �� �� �ֵ��� ���� �������� ¥�� �Ѵ�.
// �� ������ Ư���� ������ �Ϸ翡 �ϳ��� ��������� ������ �� �� �ִ�.
//

bool cmp(const pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second) return a.first > b.first;
	else return a.second > b.second;
}

int No75()
{
	system_clock::time_point start = system_clock::now();

	int N = 6, res = 0;
	vector<pair<int, int>> teach =
	{ {50, 2},
	{20, 1},
	{40, 2},
	{60, 3},
	{30, 3},
	{30, 1} };

	cout << teach[0].first << teach[0].second << endl;

	sort(teach.begin(), teach.end(), cmp);

	priority_queue<int> pQ;
	int i = 0;
	for (int j = 3; j >= 1; j--)
	{
		for (; i < teach.size(); i++)
		{
			if (teach[i].second < j) break;
			pQ.push(teach[i].first);
		}

		if (!pQ.empty())
		{
			res += pQ.top();
			pQ.pop();
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No75();

	return 0;
}