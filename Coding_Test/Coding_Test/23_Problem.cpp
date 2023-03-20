#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���� �κ� ��������
// N���� ���ڰ� ������ ����, ���������� �����ϴ� �κ� ������ �ִ� ���̸� ���Ͽ� ����Ͻÿ�.
// 5, 7, 3, 3, 12, 12, 13, 10, 11
int No23()
{
	system_clock::time_point start = system_clock::now();

	int N = 9, max = 1, temp = 1;
	vector<int> numbers = { 5, 7, 3, 3, 12, 12, 13, 10, 11 };

	for (int i = 0; i < numbers.size()-1; i++)
	{
		if (numbers[i] <= numbers[i + 1])
		{
			temp++;
			max = (max < temp) ? temp : max;
		}
		else temp = 1;
	}
	cout << max << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No23();
//
//	return 0;
//}