#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 알리바바와 40인의 도둑 Top-Down
// 알리바바는 40인의 도둑으로부터 금화를 훔쳐 도망치고 있습니다.
// 알리바바는 도망치는 길에 평소에 잘 가지 않던 계곡의 돌다리로 도망가고자 한다.
// 계곡의 돌다리는 N×N개의 돌들로 구성되어 있다.
// 각 돌다리들은 높이가 서로 다릅니다.
// 해당 돌다리를 건널때 돌의 높이 만큼 에너지가 소비됩니다.
// 이동은 최단거리 이동을 합니다.
// 즉 현재 지점에서 오른쪽 또는 아래쪽으로만 이동해야 합니다.
// N* N의 계곡의 돌다리 격자정보가 주어지면(1, 1)격자에서(N, N)까지 가는데 드는 에너지의
// 최소량을 구하는 프로그램을 작성하세요.
// 만약 N = 3이고, 계곡의 돌다리 격자 정보가 다음과 같다면
// 3  3  5
// 2  3  4
// 6  5  2
// (1, 1)좌표에서 (3, 3)좌표까지 가는데 드는 최소 에너지는 3+2+3+4+2=14이다.

vector<vector<int>> memo(21, vector<int>(21, 0));

int DFS(int x, int y, vector<vector<int>> arr)
{
	if (memo[x][y] != 0) return memo[x][y];
	if (x == 0 && y == 0) return arr[x][y];
	else
	{
		if (y == 0) return memo[x][y] = DFS(x - 1, y, arr) + arr[x][y];
		else if (x == 0) return memo[x][y] = DFS(x, y - 1, arr) + arr[x][y];
		else return memo[x][y] = min(DFS(x - 1, y, arr), DFS(x, y - 1, arr)) + arr[x][y];
	}
}

int No98()
{
	system_clock::time_point start = system_clock::now();

	int N = 5;
	vector<vector<int>> map =
	{ { 3, 7, 2, 1, 9 },
	{ 5, 8, 3, 9, 2 },
	{ 5, 3, 1, 2, 3 },
	{ 5, 4, 3, 2, 1 },
	{ 1, 7, 5, 2, 4 } };

	DFS(N - 1, N - 1, map);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No98();

	return 0;
}