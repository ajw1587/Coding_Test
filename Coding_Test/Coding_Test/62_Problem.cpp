#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 병합정렬
// N개의 숫자가 입력되면 오름차순으로 정렬하여 출력하시오.
//

vector<int> a = { 7, 6, 3, 1, 5, 2, 4, 8 };
vector<int> tmp(8, 0);

void divide(int lt, int rt)
{
	int mid;
	int p1, p2, p3;

	if (lt < rt)
	{
		mid = (lt + rt) / 2;
		p1 = lt;
		p2 = mid + 1;
		p3 = lt;

		divide(p1, mid);
		divide(p2, rt);

		while (p1 <= mid && p2 <= rt)
		{
			if (a[p1] < a[p2]) tmp[p3++] = a[p1++];
			else tmp[p3++] = a[p2++];
		}

		while (p1 <= mid) tmp[p3++] = a[p1++];
		while (p2 <= rt) tmp[p3++] = a[p2++];

		for (int i = lt; i <= rt; i++)
		{
			a[i] = tmp[i];
		}
	}
}

int No62()
{
	system_clock::time_point start = system_clock::now();

	int N = 8;

	divide(0, N - 1);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No62();

	return 0;
}