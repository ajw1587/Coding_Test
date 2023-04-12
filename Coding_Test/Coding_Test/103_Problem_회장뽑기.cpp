#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ȸ��̱� (�÷��̵�-���� ����)
// ȸ�����̿� ���� �𸣴� ����� ������, �� ����� ���ϸ� ���� ��� �� �� �ִ�.
// �� ȸ���� �ٸ� ȸ����� ����� ������ ���� ������ �ް� �ȴ�. 
// ���� ��� ��� ȸ���� �ٸ� ��� ȸ���� ģ���̸�, �� ȸ���� ������ 1���̴�.
// ��� ȸ���� ������ 2���̸�, �ٸ� ��� ȸ���� ģ���̰ų�, ģ���� ģ������ ���Ѵ�.
// ����, ��� ȸ���� ������ 3���̸�, �ٸ� ��� ȸ���� ģ���̰ų�, 
// ģ���� ģ���̰ų�, ģ���� ģ���� ģ������ ���Ѵ�.
// 4��, 5������ ���� ������� ��������.
// ȸ���� ȸ���� �߿��� ������ ���� ���� ����� �ȴ�.
// ȸ���� ������ ȸ���� �� �� �ִ� ��� ����� ã�� ���α׷��� �ۼ��Ͻÿ�.
// �� �ٿ� �� ���� ȸ����ȣ�� �ִµ�, �̰��� �� ȸ���� ���� ģ������ ��Ÿ����.
int No103()
{
	system_clock::time_point start = system_clock::now();

	int peoples = 5;
	vector<vector<int>> info =
	{ {1, 2},
	{2, 3},
	{3, 4},
	{4, 5},
	{2, 4},
	{5, 3},
	{-1, -1} };

	vector<vector<int>> dis(peoples + 1, vector<int>(peoples + 1, 500));
	for (int i = 0; i < info.size()-1; i++)
	{
		int f = info[i][0];
		int s = info[i][1];
		dis[f][s] = 1;
		dis[s][f] = 1;
	}
	for (int i = 0; i < dis.size(); i++) dis[i][i] = 0;

	for (int k = 1; k <= peoples; k++)
	{
		for (int i = 1; i < dis.size(); i++)
		{
			for (int j = 1; j < dis[i].size(); j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No103();

	return 0;
}