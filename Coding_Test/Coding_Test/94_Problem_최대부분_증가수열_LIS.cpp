#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �ִ� �κ� ��������
// N���� �ڿ����� �̷���� ������ �־����� ��,
// �� �߿��� ���� ��� �����ϴ�(���� ������ ū ����) ���ҵ��� ������ ã�� ���α׷��� �ۼ��϶�.
// ���� ���, ���Ұ� 2, 7, 5, 8, 6, 4, 7, 12, 3 �̸� ���� ��� �����ϵ��� ���ҵ��� 
// ���ʴ�� �̾Ƴ��� 2, 5, 6, 7, 12�� �̾Ƴ��� ���̰� 5�� �ִ� �κ� ���������� ���� �� �ִ�.
int No94()
{
	system_clock::time_point start = system_clock::now();

	int N = 8;
	vector<int> a = { 5, 3, 7, 8, 6, 2, 9, 4 };
	vector<int> dy(N, 0);
	int res = 0;

	dy[0] = 1;
	for (int i = 1; i < dy.size(); i++)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (a[i] > a[j] && dy[i] < dy[j] + 1)
			{
				dy[i] = dy[j] + 1;
				if (res < dy[i]) res = dy[i];
			}
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No94();

	return 0;
}