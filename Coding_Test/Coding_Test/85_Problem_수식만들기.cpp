#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���� �����
// ���̰� N�� �ڿ����� �̷���� ����
// ������ �� �� ���̿� �������� N-1���� �����ڰ� �־����ϴ�.
// ����(+), ����(-), ����(��), ������(��)
// ������ ������ �״�� ������ ä �� �׻��̿� N-1���� �����ڸ� ������ ��ġ�ϸ�
// �پ��� ������ ���ɴϴ�.
// ������ ����ϴ� ����� ������ �켱������ ������ �ʰ�
// �� ���� �����ں��� ���ʷ� ����Ѵ�.������ ����� ����� 1�̴�.
// ������ ����� �ִ��ΰͰ� �ּ��ΰ��� ����ϴ� ���α׷��� �ۼ��ϼ���.

int N = 3;
vector<int> a = { 5, 3, 8 };
int A = 0;
// +, -, *, / ����
vector<int> b = { 1, 0, 1, 0 };
int my_min = 2147000000;
int my_max = -2147000000;

void DFS(int A, int res)
{
	if (A == N)
	{
		if (res < my_min) my_min = res;
		if (res > my_max) my_max = res;
	}
	else
	{
		if (b[0] > 0)
		{
			b[0]--;
			DFS(A + 1, res + a[A]);
			b[0]++;
		}
		if (b[1] > 0)
		{
			b[1]--;
			DFS(A + 1, res - a[A]);
			b[1]++;
		}
		if (b[2] > 0)
		{
			b[2]--;
			DFS(A + 1, res * a[A]);
			b[2]++;
		}
		if (b[3] > 0)
		{
			b[3]--;
			DFS(A + 1, res / a[A]);
			b[3]++;
		}
	}
}

int No85()
{
	system_clock::time_point start = system_clock::now();

	DFS(1, a[0]);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No85();

	return 0;
}