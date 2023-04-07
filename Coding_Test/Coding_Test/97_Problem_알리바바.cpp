#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �˸��ٹٿ� 40���� ���� Bottom-Up
// �˸��ٹٴ� 40���� �������κ��� ��ȭ�� ���� ����ġ�� �ֽ��ϴ�.
// �˸��ٹٴ� ����ġ�� �濡 ��ҿ� �� ���� �ʴ� ����� ���ٸ��� ���������� �Ѵ�.
// ����� ���ٸ��� N��N���� ����� �����Ǿ� �ִ�.
// �� ���ٸ����� ���̰� ���� �ٸ��ϴ�.
// �ش� ���ٸ��� �ǳζ� ���� ���� ��ŭ �������� �Һ�˴ϴ�.
// �̵��� �ִܰŸ� �̵��� �մϴ�.
// �� ���� �������� ������ �Ǵ� �Ʒ������θ� �̵��ؾ� �մϴ�.
// N* N�� ����� ���ٸ� ���������� �־�����(1, 1)���ڿ���(N, N)���� ���µ� ��� ��������
// �ּҷ��� ���ϴ� ���α׷��� �ۼ��ϼ���.
// ���� N = 3�̰�, ����� ���ٸ� ���� ������ ������ ���ٸ�
// 3  3  5
// 2  3  4
// 6  5  2
// (1, 1)��ǥ���� (3, 3)��ǥ���� ���µ� ��� �ּ� �������� 3+2+3+4+2=14�̴�.
int No97()
{
	system_clock::time_point start = system_clock::now();

	int N = 5;
	vector<vector<int>> map =
	{ { 3, 7, 2, 1, 9 },
	{ 5, 8, 3, 9, 2 },
	{ 5, 3, 1, 2, 3 },
	{ 5, 4, 3, 2, 1 },
	{ 1, 7, 5, 2, 4 } };

	vector<vector<int>> ch_map(N, vector<int>(N, 2147000000));
	ch_map[0][0] = map[0][0];
	int up = 21476000000;
	int left = 21476000000;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == 0 && j == 0) continue;
			int x = j - 1;
			int y = i - 1;

			if (x < 0) left = 21476000000;
			else left = map[i][j] + ch_map[i][x];

			if (y < 0) up = 21476000000;
			else up = map[i][j] + ch_map[y][j];

			ch_map[i][j] = (up < left) ? up : left;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No97();

	return 0;
}