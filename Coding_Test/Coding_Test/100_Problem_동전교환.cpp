#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ������ȯ
// ������ ���� ���� ������ �������� �־��� ������ �Ž������� ���� ���� ���� �������� ��ȯ
// ���ַ��� ��� �ָ� �Ǵ°� ? �� ������ ������ ������ �� �� �ִ�.
int No100()
{
	system_clock::time_point start = system_clock::now();

	int coin_N = 3;
	vector<int> coin = { 1, 2, 5 };
	int money = 15;

	vector<int> res(money + 1, 21476000000);
	res[0] = 0;
	for (int i = 0; i < coin.size(); i++)
	{
		int c = coin[i];
		for (int j = c; j < res.size(); j++)
		{
			res[j] = min(res[j], res[j - c] + 1);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No100();

	return 0;
}