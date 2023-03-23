#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ������ ������ ������ �����ִ� map�� �־�������
// ���� 2, ���� 3 ũ�⿡�� ���� ���� ���� �� �ִ� ���� ������?
int No51()
{
	system_clock::time_point start = system_clock::now();

	vector<vector<int>> dy(8, vector<int>(9, 0));
	vector<vector<int>> map{ {0, 0, 0, 0, 0, 0, 0, 0, 0},
							{0, 3, 5, 1, 3, 1, 3, 2, 0},
							{0, 1, 2, 1, 3, 1, 1, 2, 0},
							{0, 1, 3, 1, 5, 1, 3, 4, 0},
							{0, 5, 1, 1, 3, 1, 3, 2, 0},
							{0, 3, 1, 1, 3, 1, 1, 2, 0},
							{0, 1, 3, 1, 3, 1, 2, 2, 0},
							{0, 0, 0, 0, 0, 0, 0, 0, 0} };
	int h = 6, w = 7;
	int n = 2, m = 3;
	int tmp, max = -2147000000;

	// dp ä���ֱ�
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			dy[i][j] = dy[i - 1][j] + dy[i][j - 1] - dy[i - 1][j - 1] + map[i][j];
		}
	}

	// ���� ã���ֱ�
	for (int i = n; i <= h; i++)
	{
		for (int j = m; j <= w; j++)
		{
			tmp = dy[i][j] - dy[i - n][j] - dy[i][j - m] + dy[i - n][j - m];
		}
		if (tmp > max) max = tmp;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No51();
//
//	return 0;
//}