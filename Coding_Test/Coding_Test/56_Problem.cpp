#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 재귀함수 분석 (스택을 이용하는 재귀)
// 자연수 N이 주어지면 아래와 같이 출력하는 프로그램을 작성하시오.
// 입력 : 3
// 출력 : 1 2 3

void selfFunc(int N)
{
	if (N == 0) return;
	else
	{
		selfFunc(N - 1);
		cout << N << ' ';

		return;
	}
}

int No56()
{
	system_clock::time_point start = system_clock::now();

	int N = 3;
	selfFunc(N);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No56();

	return 0;
}