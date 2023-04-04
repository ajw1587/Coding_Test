#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���ٸ� �ǳʱ�
// ö���� �б��� ���µ� ������ �������ϴ�.
// ������ N���� ���� �ٸ��� ����� ���ҽ��ϴ�.
// ö���� �� �ٸ��� �ǳ� �� �� ���� �� ĭ �Ǵ� �� ĭ�� �ǳʶٸ鼭 ���ٸ��� �ǳ� �� �ֽ��ϴ�.
// ö���� ������ �ǳʴ� ����� �� �����ϱ��?
int No93()
{
	system_clock::time_point start = system_clock::now();

	int N = 7;
	vector<int> res(N + 2, 0);

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
	No93();

	return 0;
}