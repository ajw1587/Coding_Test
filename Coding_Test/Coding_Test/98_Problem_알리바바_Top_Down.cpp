#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �˸��ٹٿ� 40���� ���� Top-Down
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

vector<vector<int>> memo(21, vector<int>(21, 0));

int DFS(int x, int y, vector<vector<int>> arr)
{
	if (memo[x][y] != 0) return memo[x][y];
	if (x == 0 && y == 0) return arr[x][y];
	else
	{
		if (y == 0) return memo[x][y] = DFS(x - 1, y, arr) + arr[x][y];
		else if (x == 0) return memo[x][y] = DFS(x, y - 1, arr) + arr[x][y];
		else return memo[x][y] = min(DFS(x - 1, y, arr), DFS(x, y - 1, arr)) + arr[x][y];
	}
}

int No98()
{
	system_clock::time_point start = system_clock::now();

	int N = 5;
	vector<vector<int>> map =
	{ { 3, 7, 2, 1, 9 },
	{ 5, 8, 3, 9, 2 },
	{ 5, 3, 1, 2, 3 },
	{ 5, 4, 3, 2, 1 },
	{ 1, 7, 5, 2, 4 } };

	DFS(N - 1, N - 1, map);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No98();

	return 0;
}