#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ����Լ� ������ ���
// 10���� N�� �ԷµǸ� 2������ ��ȯ�Ͽ� ����Ͻÿ�.
// ��, ����Լ��� �̿��Ͻÿ�.

void D(int N)
{
	if (N == 0) return;
	else
	{
		D(N / 2);
		cout << N % 2;

		return;
	}
}

int No57()
{
	system_clock::time_point start = system_clock::now();

	int N = 11;
	D(N);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No57();

	return 0;
}