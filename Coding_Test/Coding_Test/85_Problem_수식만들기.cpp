#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 수식 만들기
// 길이가 N인 자연수로 이루어진 수열
// 수열의 각 항 사이에 끼워넣을 N-1개의 연산자가 주어집니다.
// 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)
// 수열의 순서는 그대로 유지한 채 각 항사이에 N-1개의 연산자를 적절히 배치하면
// 다양한 수식이 나옵니다.
// 수식을 계산하는 결과는 연산자 우선순위를 따지지 않고
// 맨 앞쪽 연산자부터 차례로 계산한다.수식을 계산한 결과는 1이다.
// 연산한 결과가 최대인것과 최소인것을 출력하는 프로그램을 작성하세요.

int N = 3;
vector<int> a = { 5, 3, 8 };
int A = 0;
// +, -, *, / 개수
vector<int> b = { 1, 0, 1, 0 };
int my_min = 2147000000;
int my_max = -2147000000;

void DFS(int A, int res)
{
	if (A == N)
	{
		if (res < my_min) my_min = res;
		if (res > my_max) my_max = res;
	}
	else
	{
		if (b[0] > 0)
		{
			b[0]--;
			DFS(A + 1, res + a[A]);
			b[0]++;
		}
		if (b[1] > 0)
		{
			b[1]--;
			DFS(A + 1, res - a[A]);
			b[1]++;
		}
		if (b[2] > 0)
		{
			b[2]--;
			DFS(A + 1, res * a[A]);
			b[2]++;
		}
		if (b[3] > 0)
		{
			b[3]--;
			DFS(A + 1, res / a[A]);
			b[3]++;
		}
	}
}

int No85()
{
	system_clock::time_point start = system_clock::now();

	DFS(1, a[0]);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No85();

	return 0;
}