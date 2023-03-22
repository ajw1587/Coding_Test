#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���ڰ� N��
// ���ڵ��� ���� ������ 1������ N������ ���ʷ� ��ȣ�� �ű��.
// �׸��� 1�� ���ں��� N�� ���ڱ��� ������� �ð�������� ���ư��� ���׶��� �ɰ� �Ѵ�.
// �׸��� 1�� ���ں��� �ð�������� ���ư��� 1���� �����Ͽ� ��ȣ�� ��ġ�� �Ѵ�.
// �� ���ڰ� K(Ư�� ����)�� ��ġ�� �� ���ڴ� ���ָ� ���Ϸ� ���µ��� ���ܵǰ�
// �� ������ ������ �ȴ�.
// �׸��� ���� ���ں��� �ٽ� 1���� �����Ͽ� ��ȣ�� ��ģ��.
// ���������� ���� ���ڴ�?
int My_No45()
{
	system_clock::time_point start = system_clock::now();

	int N = 8, K = 3;
	vector<int> princes = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<bool> check(N, true);
	int pos = 0, temp = 1, cnt = princes.size();

	while (cnt != 1)
	{
		pos++;
		temp++;

		if (pos >= cnt) pos = 0;

		if (temp == K)
		{
			cnt--;
			princes.erase(princes.begin() + pos);
			temp = 0;
			pos--;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int No45()
{
	system_clock::time_point start = system_clock::now();

	int N = 8, K = 3;
	vector<int> princes(8, 0);
	int pos = 0, bp = 0, cnt = 0;
	
	while (1)
	{
		pos++;
		if (pos >= N) pos = 0;
		if (princes[pos] == 0)
		{
			cnt++;
			if (cnt == K)
			{
				princes[pos] = 1;
				cnt = 0;
				bp++;
			}
		}
		if (bp == N - 1) break;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	My_No45();		// 56
//	No45();			// 6
//
//	return 0;
//}