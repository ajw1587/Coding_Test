#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 합이 같은 부분집합 (DFS : 아마존 인터뷰)
// N개의 원소로 구성된 자연수 집합이 주어지면,
// 이 집합을 두 개의 부분 집합으로 나누었을 때,
// 두 부분집합의 원소의 합이 서로 같은 경우가 존재하면 "YES", 그렇지 않으면 "NO"를 출력하시오.
// 
// ex)
// 입력 : 1, 3, 5, 6, 7, 10
// 1, 3, 5, 7 = 6, 10 두 부분집합의 합이 같으므로 "YES"

int N = 6;
vector<int> a = { -99, 1, 3, 5, 6, 7, 10 };
int total = 32;
bool flag = false;

void DFS(int L, int sum)
{
	if (flag == true || sum > total / 2) return;
	if (L == N + 1)
	{
		if (sum == (total - sum))
		{
			flag = true;
		}
	}
	else
	{
		DFS(L + 1, sum + a[L]);
		DFS(L + 1, sum);
	}
}

int No60()
{
	system_clock::time_point start = system_clock::now();

	DFS(1, 0);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No60();

	return 0;
}