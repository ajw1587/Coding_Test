#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// Bottom Up
// ��Ʈ��ũ ���� 1m, 2m�� ���̸� ���� ������ �ڸ����� �մϴ�.
// ���� ��� 4m�� ��Ʈ��ũ ���� �־����ٸ�
// 1) 1m + 1m + 1m + 1m
// 2) 2m + 1m + 1m
// 3) 1m + 2m + 1m
// 4) 1m + 1m + 2m
// 5) 2m + 2m
int No91()
{
	system_clock::time_point start = system_clock::now();

	int N = 7;
	vector<int> res(N + 1, 0);

	res[1] = 1;
	res[2] = 2;
	for (int i = 3; i < res.size(); i++)
	{
		res[i] = res[i - 1] + res[i - 2];
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No91();

	return 0;
}