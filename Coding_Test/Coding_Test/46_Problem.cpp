#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ��Ƽ�½�ŷ (īī�� �Թ� ���� ����)
// ó���ؾ� �� �۾��� N�� ������,
// ������ ��ǻ�ʹ� �۾��� 1���� N������ ��ȣ�� �ο��ϰ� �Ʒ��� ���� ó���Ѵ�.
// 1. 1�� �۾����� ������� 1�ʾ� �۾��� �Ѵ�.
// 2. ������ ��ȣ�� �۾��� 1�� ������ �ٽ� 1�� �۾����� ���� �ٽ� 1�ʾ� �ļ� ó�� �Ѵ�.
// 3. ó���� ���� �۾��� �����쿡�� ������� ���ο� �۾��� ������ �ʴ´�.
//	  �׷��� ���� �������� K�� �Ŀ� ������ �Ǿ� ��ǻ�Ͱ� �Ͻ������� ���߾���.
//	  ���Ⱑ ������ ���� ������ ��ǻ�Ͱ� �� �� �۾����� �ٽ� �����ؾ� �ϴ��� ����Ͻÿ�.
// N : �۾��� ����, K : ���� ���� �ð�
int No46()
{
	system_clock::time_point start = system_clock::now();

	int N = 3, K = 5;
	vector<int> work = { 1, 2, 3 };
	int pos = 0, seconds = 0;

	while (seconds != K)
	{
		if (pos >= N) pos = 0;
		if (work[pos] != 0)
		{
			work[pos]--;
			seconds++;
		}
		pos++;
	}

	cout << pos + 1 << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No46();
//
//	return 0;
//}