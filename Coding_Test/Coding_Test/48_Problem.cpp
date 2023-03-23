#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �� ���� ��հ� ���� ����� ��
// 9 x 9 �����ǿ� ������ 81���� �ڿ����� �־��� ��,
// �� ���� ����� ���ϰ�, �� ��հ� ���� ����� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// ����� �Ҽ��� ù ° �ڸ����� �ݿø� �մϴ�.
// ��հ� ����� ���� �ΰ��̸� �� �� ū ���� ����ϼ���.
int No48()
{
	system_clock::time_point start = system_clock::now();

	vector<vector<int>> arr =
	{ {3, 23, 85, 34, 17, 74, 25, 52, 65},
	{10, 7, 39, 42, 88, 52, 14, 72, 63},
	{87, 42, 18, 78, 53, 45, 18, 84, 53},
	{34, 28, 64, 85, 12, 16, 75, 36, 55},
	{21, 77, 45, 35, 28, 75, 90, 76, 1},
	{25, 87, 65, 15, 28, 11, 37, 28, 74},
	{65, 27, 75, 41, 7, 89, 78, 64, 39},
	{47, 47, 70, 45, 23, 65, 3, 41, 44},
	{87, 13, 82, 38, 50, 12, 48, 29, 80} };

	int size = arr.size();
	int i, j, sum, avg, min, tmp, res;
	for (int i = 0; i < size; i++)
	{
		sum = 0;
		for (j = 0; j < size; j++)
		{
			sum += arr[i][j];
		}
		avg = sum / 9 + 0.5;
		min = 2147000000;
		for (j = 0; j < size; j++)
		{
			tmp = abs(arr[i][j] - avg);
			if (min > tmp)
			{
				min = tmp;
				res = arr[i][j];
			}
			else if (tmp == min)
			{
				if (res > arr[i][j]) res = arr[i][j];
			}
		}
		cout << res << endl;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No48();
//
//	return 0;
//}