#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 이항 계수 (메모이제이션)
// 이항계수는 N개의 원소를 가지는 집합에서 R개의 원소를 뽑아 부분집합을 만드는 
///경우의 수를 의미한다.
// 공식은 nCr 로 표현된다.
// N과 R이 주어지면 이항계수를 구하는 프로그램을 작성하세요.
//

int FAC(int n)
{
	if (n == 1) return 1;
	else return n * FAC(n - 1);
}

vector<vector<int>> dp(5, vector<int>(3, 0));
int DFS(int n, int r)
{
	if (dp[n][r] > 0) return dp[n][r];
	if (n == r || r == 0) return 1;
	else return dp[n][r] = DFS(n - 1, r - 1) + DFS(n - 1, r);
}

int No76()
{
	system_clock::time_point start = system_clock::now();

	int N = 5, R = 3, cnt = 0;

	int fac_test = FAC(5);
	int dfs_test = DFS(N, R);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No76();

	return 0;
}