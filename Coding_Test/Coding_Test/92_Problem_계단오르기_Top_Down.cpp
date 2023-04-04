#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 철수는 계단을 오를 때 한 번에 한 계단 또는 두 계단씩 올라간다.
// 만약 총 4계단을 오른다면 그 방법의 수는
// 1 + 1 + 1 + 1, 1 + 1 + 2, 1 + 2 + 1, 2 + 1 + 1, 2 + 2 로 5가지이다.
// 그렇다면 총 N계단일 때 철수가 올라갈 수 있는 방법의 수는 몇 가지인가 ?

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
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No92();

	return 0;
}