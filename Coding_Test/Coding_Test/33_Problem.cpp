#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ��������
// 3���� ����
// ������ ���ʴ�� �ԷµǸ� 3���� ������??
int No33()
{
	system_clock::time_point start = system_clock::now();

	vector<int> points = { 80, 96, 75, 82, 96, 92, 100 };
	int temp, idx, max = -1, rank = 0;

	// ��������
	for (int i = 0; i < points.size() - 1; i++)
	{
		idx = i;
		for (int j = i + 1; j < points.size(); j++)
		{
			if (points[idx] < points[j]) idx = j;
		}
		temp = points[i];
		points[i] = points[idx];
		points[idx] = temp;
	}

	for (int i = 0; i < points.size()-1; i++)
	{
		if (points[i] != points[i + 1]) rank++;
		if (rank == 3)
		{
			cout << points[i] << endl;
			break;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No33();
//
//	return 0;
//}