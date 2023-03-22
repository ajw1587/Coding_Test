#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���ӵ� �ڿ����� ��
// �Է����� ���� ���� N�� �ԷµǸ� 2�� �̻��� ���ӵ� �ڿ����� ������ ���� N�� ǥ���ϴ� ����� �������� ����Ͻÿ�.
// N = 15
// 7 + 8
// 4 + 5 + 6
// 1 + 2 + 3 + 4 + 5
int My_No41()
{
	system_clock::time_point start = system_clock::now();

	int N = 15;
	int cnt = 0;
	int ans = 0;

	for (int i = 1; i <= N / 2 + 1; i++)
	{
		for (int j = i; j <= N / 2 + 1; j++)
		{
			cnt += j;
			if (cnt == N)
			{
				ans++;
				break;
			}
		}
		cnt = 0;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int No41()
{
	system_clock::time_point start = system_clock::now();

	int ans = 0;
	int N = 15;
	int temp = 0;
	int b = 1;

	temp = N;
	N--;
	while (N > 0)
	{
		b++;
		N -= b;
		if (N % b == 0) ans++;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	My_No41();
//	No41();
//
//	return 0;
//}