#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 인접행렬
//6 9
//1 2 7
//1 3 4
//2 1 2
//2 3 5
//2 5 5
//3 4 5
//4 2 2
//4 5 5
//6 4 5
int No63()
{
	system_clock::time_point start = system_clock::now();



	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No63();

	return 0;
}