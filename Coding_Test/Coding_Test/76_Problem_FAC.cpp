#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���� ��� (�޸������̼�)
// ���װ���� N���� ���Ҹ� ������ ���տ��� R���� ���Ҹ� �̾� �κ������� ����� 
///����� ���� �ǹ��Ѵ�.
// ������ nCr �� ǥ���ȴ�.
// N�� R�� �־����� ���װ���� ���ϴ� ���α׷��� �ۼ��ϼ���.
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No76();

	return 0;
}