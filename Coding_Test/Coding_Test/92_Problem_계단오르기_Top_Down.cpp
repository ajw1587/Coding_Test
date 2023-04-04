#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ö���� ����� ���� �� �� ���� �� ��� �Ǵ� �� ��ܾ� �ö󰣴�.
// ���� �� 4����� �����ٸ� �� ����� ����
// 1 + 1 + 1 + 1, 1 + 1 + 2, 1 + 2 + 1, 2 + 1 + 1, 2 + 2 �� 5�����̴�.
// �׷��ٸ� �� N����� �� ö���� �ö� �� �ִ� ����� ���� �� �����ΰ� ?

int DFS(int N, vector<int>& res)
{
	if (N == 1 || N == 2) return res[N] = N;
	if (res[N] != 0) return res[N];
	else
	{
		return res[N] = DFS(N - 1, res) + DFS(N - 2, res);
	}
}

int No92()
{
	system_clock::time_point start = system_clock::now();

	int N = 7;
	vector<int> res(N + 1, 0);

	int test = DFS(N, res);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No92();

	return 0;
}