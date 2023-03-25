#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 특정 수 만들기 (DFS : MS 인터뷰)
// N개의 원소로 구성된 자연수 집합이 주어지면,
// 집합의 원소와 '+', '-' 연산을 사용하여 특정 수인 M을 만드는 경우가
// 몇 가지 있는지 출력하시오.
// 
// ex)
// 입력 : {2, 4, 6, 8}, M = 12
// 총 4가지
//

int N = 4, M = 12;
vector<int> a = { 2, 4, 6, 8 };
int cnt = 0;

void DFS(int idx, int res)
{
	if (idx >= N)
	{
		if (res == M) cnt++;
		return;
	}
	else
	{
		DFS(idx + 1, res + a[idx]);
		DFS(idx + 1, res - a[idx]);
		DFS(idx + 1, res);
	}
}

int No61()
{
	system_clock::time_point start = system_clock::now();

	int idx = 0, res = 0;
	DFS(idx, res);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No61();

	return 0;
}