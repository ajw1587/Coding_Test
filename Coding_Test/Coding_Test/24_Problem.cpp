#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// Jolly Jumpers
// N���� ������ �̷���� ������ ���� ���� ������ �ִ� �� ���� ���� 1���� N-1������ ���� ��� ������
// �� ������ ������ ���۶�� �θ���.
// 1, 4, 2, 3 �� �ڿ� �ִ� ���� ���� ���� ���� ���� 3, 2, 1�̹Ƿ� ������ ���۴�.
int No24()
{
	system_clock::time_point start = system_clock::now();

	int N = 5, temp = 0;
	vector<int> numbers = { 1, 4, 2, 3, 7 };
	vector<bool> check(N, false);
	check[0] = true;

	for (int i = 0; i < N-1; i++)
	{
		temp = abs(numbers[i + 1] - numbers[i]);

		if (check[temp])
		{
			cout << "NO" << endl;
			return 0;
		}
		else
		{
			check[temp] = true;
		}
	}

	if (find(check.begin(), check.end(), false) != check.end())
	{
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No24();
//
//	return 0;
//}