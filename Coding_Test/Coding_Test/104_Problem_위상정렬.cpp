#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// ��������
// ���������� � ���� �ϴ� ������ ã�� �˰����Դϴ�.
// ������ ���� ���İ��谡 �����ϰ� �������� �� ���� ���� ���İ��踦 �����ϸ鼭 ��ü ����
// ������ ¥�� �˰����Դϴ�.
// ���� �Ʒ��� ���� ���� ������ ���� ��Ű�鼭 ��ü ���� ������ ���Ѵٸ�
// 1 4 -> 1������ �ϰ� �� �� 4������ �ؾ��Ѵ�.
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

	// ����ϱ� ���� �ʿ��� ���� ���� Ƚ�� �����ֱ�
	vector<int> degree(N + 1, 0);
	for (int i = 0; i < info.size(); i++)
	{
		int start = info[i][0];
		int end = info[i][1];
		degree[end]++;
	}

	// info �������ֱ�
	vector<vector<int>> new_info(N + 1);
	for (int i = 0; i < info.size(); i++)
	{
		new_info[info[i][0]].push_back(info[i][1]);
	}

	// ���� ���� Ƚ���� 0�� �κ� Q�� �־��ֱ�
	queue<int> Q;
	for (int i = 1; i < degree.size(); i++)
	{
		if (degree[i] == 0) Q.push(i);
	}

	// �ϳ��� ������ ���� Ƚ�� �����ϱ�
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No104();

	return 0;
}