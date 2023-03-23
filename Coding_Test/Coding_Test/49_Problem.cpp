#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���鿡�� �� �ܸ�� ������ ���鿡�� �� �ܸ��� �ְ�
// �ִ� ��� ������ ����Ͽ� ����� ������ ���鿡�� �� ������� ����� ������ �߽��ϴ�.
// ����� �״µ� ����ؾ� �� �ִ� ������ ����Ͻÿ�.
// ù �ٿ��� ����� ũ�� N
// �� ��° �ٿ��� ���鿡���� ���� ����
// �� ��° �ٿ��� ������ ���� ���� ����
int No49()
{
	system_clock::time_point start = system_clock::now();

	int N = 4;
	vector<int> front = { 2, 0, 3, 1 };
	vector<int> right = { 1, 1, 2, 3 };
	int f_sum = -1, r_sum = -1, res = 0;

	while (f_sum != 0 && r_sum != 0)
	{
		f_sum = 0;
		r_sum = 0;
		for (int i = 0; i < front.size(); i++)
		{
			if (front[i] > 0)
			{
				f_sum += 1;
				front[i]--;
			}
		}

		for (int i = 0; i < right.size(); i++)
		{
			if (right[i] > 0)
			{
				r_sum += 1;
				right[i]--;
			}
		}

		res = res + f_sum * r_sum;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No49();
//
//	return 0;
//}