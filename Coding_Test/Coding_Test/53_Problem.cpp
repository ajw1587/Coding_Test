#include <iostream>
#include <chrono>
#include <vector>
#include <stack>

using namespace std;
using namespace chrono;

// K���� ���
// 10���� N�� �ԷµǸ� K������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
// Stack �ڷᱸ�� ���!
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No53();
//
//	return 0;
//}