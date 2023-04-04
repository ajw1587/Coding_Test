#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// Top Down
// ��Ʈ��ũ ���� 1m, 2m�� ���̸� ���� ������ �ڸ����� �մϴ�.
// ���� ��� 4m�� ��Ʈ��ũ ���� �־����ٸ�
// 1) 1m + 1m + 1m + 1m
// 2) 2m + 1m + 1m
// 3) 1m + 2m + 1m
// 4) 1m + 1m + 2m
// 5) 2m + 2m

int DFS(int N, vector<int> &res)
{
	if (res[N] != 0) return res[N];
	if (N == 1 || N == 2)
	{
		return N;
	}
	else
	{
		return res[N] = DFS(N - 1, res) + DFS(N - 2, res);
	}
}

int No91()
{
	system_clock::time_point start = system_clock::now();

	int N = 45;
	vector<int> dy(N + 1, 0);

	int res = DFS(N, dy);

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