#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 멀티태스킹 (카카오 먹방 문제 변형)
// 처리해야 할 작업이 N개 들어오면,
// 현수의 컴퓨터는 작업을 1부터 N까지의 번호를 부여하고 아래와 같이 처리한다.
// 1. 1번 작업부터 순서대로 1초씩 작업을 한다.
// 2. 마지막 번호의 작업을 1초 했으면 다시 1번 작업으로 가서 다시 1초씩 후속 처리 한다.
// 3. 처리가 끝난 작업은 스케쥴에서 사라지고 새로운 작업은 들어오지 않는다.
//	  그런데 일을 시작한지 K초 후에 정전이 되어 컴퓨터가 일시적으로 멈추었다.
//	  전기가 들어오고 나서 현수의 컴퓨터가 몇 번 작업부터 다시 시작해야 하는지 출력하시오.
// N : 작업의 개수, K : 정전 시작 시간
int No46()
{
	system_clock::time_point start = system_clock::now();

	int N = 3, K = 5;
	vector<int> work = { 1, 2, 3 };
	int pos = 0, seconds = 0;

	while (seconds != K)
	{
		if (pos >= N) pos = 0;
		if (work[pos] != 0)
		{
			work[pos]--;
			seconds++;
		}
		pos++;
	}

	cout << pos + 1 << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No46();
//
//	return 0;
//}