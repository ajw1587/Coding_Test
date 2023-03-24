#include <iostream>
#include <chrono>
#include <vector>
#include <stack>

using namespace std;
using namespace chrono;

// K진수 출력
// 10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하시오.
// Stack 자료구조 사용!
int No53()
{
	system_clock::time_point start = system_clock::now();

	int N = 11, K = 2, temp = 0;
	stack<int> buffer;

	while (N != 0)
	{
		buffer.push(N % K);
		N /= K;
	}

	while (buffer.empty() != 0)
	{
		cout << buffer.top() << ' ';
		buffer.pop();
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No53();
//
//	return 0;
//}