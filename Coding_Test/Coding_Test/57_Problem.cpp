#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 재귀함수 이진수 출력
// 10진수 N이 입력되면 2진수로 변환하여 출력하시오.
// 단, 재귀함수를 이용하시오.

void D(int N)
{
	if (N == 0) return;
	else
	{
		D(N / 2);
		cout << N % 2;

		return;
	}
}

int No57()
{
	system_clock::time_point start = system_clock::now();

	int N = 11;
	D(N);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No57();

	return 0;
}