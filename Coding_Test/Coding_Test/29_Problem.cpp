#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �ڿ��� N�� �־������� 1���� N���� 3�� ����
int No29()
{
	system_clock::time_point start = system_clock::now();

	int N = 15, count = 0, tmp = 0;
	
	for (int i = 1; i <= N; i++)
	{
		tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 3) count++;
			tmp /= 10;
		}
	}
	cout << count << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No29();
//
//	return 0;
//}