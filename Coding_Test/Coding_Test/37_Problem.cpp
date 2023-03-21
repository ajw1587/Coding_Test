#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// īī�� ĳ�� ���� ����
// LRU �˰����� ������. ���� �������� ������� ���� ���� ����.
// ex) 2, 3, 1, 6, 7 (�� ���� ���� �ֱٿ� ���� �۾�)
// 1. Cache Miss : �ؾ��� �۾��� ĳ�ÿ� ���� ����
//				   5�� ������ 5�� ���� �տ� ��ġ 5, 2, 3, 1, 6
// 2. Cache Hit : �ؾ��� �۾��� ĳ�ÿ� �ִ� ����
//				   3�� �۾��� �Ѵٸ� 3, 5, 2, 1, 6
// ĳ�� ũ�Ⱑ �־�����, ����ִ� ���¿��� N���� �۾��� ó���Ѵٸ� ĳ�ø޸��� ���´�?
int No37()
{
	system_clock::time_point start = system_clock::now();

	vector<int> input_array = { 1, 2, 3, 2, 6, 2, 3, 5, 7 };
	vector<int> c(5, 0);
	int input = -1, size = 9;
	int	temp = -1, idx = -1;
	
	for (int i = 0; i < size; i++)
	{
		input = input_array[i];

		idx = -1;
		for (int j = 0; j < c.size(); j++) if (c[j] == input) idx = j;

		if (idx == -1)
		{
			for (int k = c.size() - 1; k >= 1; k--) c[k] = c[k - 1];
		}
		else
		{
			for (int k = idx; k >= 1; k--) c[k] = c[k - 1];
		}
		c[0] = input;
	}


	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No37();
//
//	return 0;
//}