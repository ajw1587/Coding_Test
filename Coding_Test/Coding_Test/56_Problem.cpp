#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ����Լ� �м� (������ �̿��ϴ� ���)
// �ڿ��� N�� �־����� �Ʒ��� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// �Է� : 3
// ��� : 1 2 3

void selfFunc(int N)
{
	if (N == 0) return;
	else
	{
		selfFunc(N - 1);
		cout << N << ' ';

		return;
	}
}

int No56()
{
	system_clock::time_point start = system_clock::now();

	int N = 3;
	selfFunc(N);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No56();

	return 0;
}