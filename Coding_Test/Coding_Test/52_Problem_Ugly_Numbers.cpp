#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// Ugly Numbers (Three Pointer Algorithm)
// 어떤 수를 소인수분해 했을 때 그 소인수가 2 또는 3 또는 5로만 이루어진 수를
// Ugly Number라고 부릅니다.
// Ugly Number를 차례대로 적어보면
// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ... 입니다.
// 숫자 1은 Ugly Number의 첫 번째 수로 합니다.
// 자연수 N이 주어지면 Ugly Number를 차례로 적을 때 N번째 Ugly Number를 구하시오.
// 3 <= N <= 1500
int No52()
{
	system_clock::time_point start = system_clock::now();

	int N = 10;
	int p2 = 1, p3 = 1, p5 = 1;
	int tmp = 2147000000;
	bool flag2 = false, flag3 = false, flag5 = false;
	vector<int> n(N + 1, 0);

	n[1] = 1;
	for (int i = 2; i < n.size(); i++)
	{
		if (n[p2] * 2 < n[p3] * 3) tmp = n[p2] * 2;
		else tmp = n[p3] * 3;
		if (n[p5] * 5 < tmp) tmp = n[p5] * 5;

		if (tmp == n[p2] * 2) p2++;
		if (tmp == n[p3] * 3) p3++;
		if (tmp == n[p5] * 5) p5++;

		n[i] = tmp;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No52();
//
//	return 0;
//}