#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �ִ� ���� ���ϱ�
// �̹� �����ø��ǾƵ��ȸ���� ���� ������ ���� ���Ͽ� ������ �������� �ֽ� N���� ������ Ǯ���� �մϴ�.
// �� ������ �װ��� Ǯ���� �� ��� ������ Ǫ�µ� �ɸ��� �ð��� �־����� �˴ϴ�.
// ���ѽð� M�ȿ� N���� ���� �� �ִ������� ���� �� �ֵ��� �ؾ� �մϴ�. 
// (�ش繮���� �ش�ð��� �ɸ��� Ǫ�� �ɷ� �����Ѵ�, �� ������ �Ѱ��� Ǯ �� �ֽ��ϴ�.)
int No101()
{
	system_clock::time_point start = system_clock::now();

	int problem = 5, minute = 20;
	vector<vector<int>> p_t =
	{ { 10, 5 },
	{ 25, 12},
	{ 15, 8},
	{ 6, 3},
	{ 7, 4} };

	vector<int> res(minute + 1, 0);

	for (int i = 0; i < p_t.size(); i++)
	{
		int t = p_t[i][1];
		int p = p_t[i][0];
		for (int j = t; j < res.size(); j++)
		{
			res[j] = max(res[j], res[j - t] + p);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No101();

	return 0;
}