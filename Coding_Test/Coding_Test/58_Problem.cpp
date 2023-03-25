#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 이진트리 깊이우선 탐색(DFS)
//			1
//		2		3
//	  4   5   6   7
// 위 그림과 같은 이진트리를 전위순회와 후위순회를 작성하시오.
// 
// 전위순회 : 1 2 4 5 3 6 7
// 중위순회 : 4 2 5 1 6 3 7
// 후위순회 : 4 5 2 6 7 3 1
//

void D1(int v)		// 전위 순회
{
	if (v > 7) return;
	else
	{
		cout << v << ' ';
		D1(v * 2);
		D1(v * 2 + 1);
	}
}

void D2(int v)		// 중위 순회
{
	if (v > 7) return;
	else
	{
		D2(v * 2);
		cout << v << ' ';
		D2(v * 2 + 1);
	}

}

void D3(int v)
{
	if (v > 7) return;
	else
	{
		D3(v * 2);
		D3(v * 2 + 1);
		cout << v << ' ';
	}
}

int No58()
{
	system_clock::time_point start = system_clock::now();

	D1(1);
	cout << endl;
	D2(1);
	cout << endl;
	D3(1);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No58();

	return 0;
}