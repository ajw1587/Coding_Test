#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 1: ����, 2: ����, 3: ��
// �� N���� ������ �Ͽ� A�� �̱�� A�� ���, B�� �̱�� B�� ����Ͻÿ�. ��� ��� D ���.
int No20()
{
	system_clock::time_point start = system_clock::now();

	int N = 5;
	vector<int> A = { 2, 3, 3, 1, 3 };
	vector<int> B = { 1, 1, 2, 2, 3 };

	for (int i = 0; i < N; i++)
	{
		int tmp = A[i] - B[i];
		if (tmp > 0 && tmp < 2) cout << "A" << endl;
		else if (tmp == 0) cout << "D" << endl;
		else cout << "B" << endl;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No20();
//
//	return 0;
//}