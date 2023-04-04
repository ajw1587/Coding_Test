#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �ִ� �� �����ϱ�
// ������ ��ȣ�� �������� ��ȣ�� �ִ� �׸����� ���� ��ȣ���� ������ �����Ϸ��� �մϴ�. 
// ���ʹ�ȣ�� ������ ���������� ���ʷ� 1���� N���� ������������ �����Ǿ� �ֽ��ϴ�.
// �������� ��ȣ ������ ������ �Ʒ� ������ �־����� ���� ���� ��ġ�� �ʰ�
// �ִ� �� ���� ���� ������ �� �ִ� �� ���ϴ� ���α׷��� �ۼ��ϼ���.

int No95()
{
	system_clock::time_point start = system_clock::now();

	int N = 10;
	vector<int> numbers = { 4, 1, 2, 3, 9, 7, 5, 6, 10, 8 };
	vector<int> res(N, 1);

	res[0] = 1;
	for (int i = 1; i < res.size(); i++)	// res
	{
		for (int j = i; j > 0; j--)
		{
			if (numbers[i] > numbers[j] && res[i] < res[j] + 1)
			{
				res[i] = res[j] + 1;
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
	No95();

	return 0;
}