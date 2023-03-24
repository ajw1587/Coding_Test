#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 이진트리 깊이우선 탐색(DFS)
int No58()
{
	system_clock::time_point start = system_clock::now();



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