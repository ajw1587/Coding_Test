#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 각 행의 평균과 가장 가까운 값
int No48()
{
	system_clock::time_point start = system_clock::now();



	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No48();
//
//	return 0;
//}