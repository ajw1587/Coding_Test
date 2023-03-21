#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// Inversion Sequence
// 1���� n������ ���� �� ������ ����Ͽ� �̷���� ������ ���� ��,
// 1���� n���� ������ �� �տ� ���� �ִ� �ڽź��� ū ������ ������ ������ ǥ���� ���� Inversion Sequence��� �Ѵ�.
// ���� ���,
// 4, 8, 6, 2, 5, 1, 3, 7
// 1 �տ� ���� 1���� ū ���� 4, 8, 6, 2, 5 �̷��� 5��
// 2 �տ� ���� 2���� ū ���� 4, 8, 6 �̷��� 3��
// 3 �տ� ���� 3���� ū ���� 4, 8, 6, 5 �̷��� 4��
// ���� Inversion Sequence�� 5, 3, 4, 0, 2, 1, 1, 0 �� �ȴ�.
// Inversion Sequence�� �־����� ������ ������ ���Ͻÿ�.
int My_No38()
{
	system_clock::time_point start = system_clock::now();

	int size = 8;	// ���ڴ� 1 ~ 8 ���� ���
	int temp, idx, num = -1, cnt = 0;
	vector<int> is = { 5, 3, 4, 0, 2, 1, 1, 0 };
	vector<int> ans(size, 0);

	for (int i = is.size() - 1; i >= 0; i--)
	{
		num = i + 1;
		cnt = 0;
		// num�� �� idx ã��
		for (idx = 0; idx < ans.size(); idx++)
		{
			if (cnt == is[i])
			{
				break;
			}
			if (ans[idx] > num)
			{
				cnt++;
			}
		}

		// �� �ڸ� �������ֱ�
		for (int i = ans.size()-1; i > idx; i--)
		{
			temp = ans[i];
			ans[i] = ans[i - 1];
			ans[i - 1] = temp;
		}
		ans[idx] = num;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int No38()
{
	system_clock::time_point start = system_clock::now();

	int size = 8;	// ���ڴ� 1 ~ 8 ���� ���
	int temp, pos, j, cnt = 0;
	vector<int> is = { -99, 5, 3, 4, 0, 2, 1, 1, 0 };
	vector<int> os(size+1, 0);

	for (int i = size; i >= 1; i--)
	{
		pos = i;
		for (j = 1; j <= is[i]; j++)
		{
			os[pos] = os[pos + 1];
			pos++;
		}
		os[pos] = i;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	My_No38();	// 72
//	No38();		// 5
//
//	return 0;
//}