#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 돌다리 건너기
// 철수는 학교에 가는데 개울을 만났습니다.
// 개울은 N개의 돌로 다리를 만들어 놓았습니다.
// 철수는 돌 다리를 건널 때 한 번에 한 칸 또는 두 칸씩 건너뛰면서 돌다리를 건널 수 있습니다.
// 철수가 개울을 건너는 방법은 몇 가지일까요?
int No93()
{
	system_clock::time_point start = system_clock::now();

	int N = 7;
	vector<int> res(N + 2, 0);

	res[1] = 1;
	res[2] = 2;
	for (int i = 3; i < res.size(); i++)
	{
		res[i] = res[i - 1] + res[i - 2];
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No93();

	return 0;
}