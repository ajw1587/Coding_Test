#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 카운셀러로 일하고 있는 현수는 오늘부터 N+1일째 되는 날 휴가를 가기 위해서, 
// 남은 N일 동안 최대한 많은 상담을 해서 휴가비를 넉넉히 만들어 휴가를 떠나려 한다.
// 현수가 다니는 회사에 하루에 하나씩 서로 다른 사람의 상담이 예약되어 있다.
// 각각의 상담은 상담을 완료하는데 걸리는 날수 T와
// 상담을 했을 때 받을 수 있는 금액 P로 이루어져 있다.
// 만약 N = 7이고, 아래와 같이 예약이 잡혔있다면
//   1일 2일 3일 4일 5일 6일 7일
// T  4   2   3   3  2   2   1
// P 20  10  15  20  30  20  10

int answer = 0;

void DFS(int idx, vector<vector<int>> sc, int res)
{
	if (idx == 7)
	{
		answer = (answer < res) ? res : answer;
		return;
	}
	else
	{
		if (idx + sc[idx][0] <= 7) DFS(idx + sc[idx][0], sc, res + sc[idx][1]);
		DFS(idx + 1, sc, res);
	}
}

int No84()
{
	system_clock::time_point start = system_clock::now();

	int N = 7;
	int res = 0;
	vector<vector<int>> sc =
	{{ 4, 20 },
	{ 2, 10 },
	{ 3, 15 },
	{ 3, 20 },
	{ 2, 30 },
	{ 2, 20 },
	{ 1, 10 }};

	DFS(0, sc, res);

	cout << answer << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No84();

	return 0;
}