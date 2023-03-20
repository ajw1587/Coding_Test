#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �µ��� �ִ밪
// �������� ��ĥ������ �µ��� ���� ���� ū ���� ���Ͻÿ�.
// N : ��ü ��¥�� ��, K : �������� ��¥�� ��
// 3, -2, -4, -9, 0, 3, 7, 13, 8, -3
int No22()
{
	system_clock::time_point start = system_clock::now();

	int N = 10, K = 2, sum = 0, max = -1;
	vector<int> temper = { 3, -2, -4, -9, 0, 3, 7, 13, 8, -3 };

	for (int i = 0; i < K; i++) sum += temper[i];

	max = sum;
	for (int i = 1; i < N-K; i++)
	{
		sum -= temper[i-1];
		sum += temper[i+K-1];

		max = (max < sum) ? sum : max;
	}
	cout << max << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No22();
//
//	return 0;
//}