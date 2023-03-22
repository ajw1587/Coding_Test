#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 이분 탐색
// 임의의 N개의 숫자가 입력으로 주어진다.
// N개의 수를 오름차순으로 정렬한 다음 N개의 수 중 한 개의 수인 M이 주어지면
// 이분탐색으로 M이 정렬된 상태에서 몇 번째에 있는지 구하시오.
// ex)
// 8, 32
// 23, 87, 65, 12, 57, 32, 99, 81
// 출력 : 3

static vector<int> insertSort(vector<int> v)
{
	int temp, j;

	for (int i = 1; i < v.size(); i++)
	{
		temp = v[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (temp < v[j]) v[j + 1] = v[j];
			else break;
		}
		v[j + 1] = temp;
	}

	return v;
}

int My_No42()
{
	system_clock::time_point start = system_clock::now();

	vector<int> v = { 23, 87, 65, 12, 57, 32, 99, 81 };
	int size = v.size(), pos = size / 2;
	int ans = -1, M = 32, temp = -1;

	// 정렬해주기
	// 12 23 32 57 65 81 87 99
	v = insertSort(v);

	// 원하는 값 찾아주기
	while (temp != M)
	{
		temp = v[pos];
		if (temp > M) pos = pos / 2;
		else if (temp < M) pos = (size - pos - 1) / 2;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int No42()
{
	system_clock::time_point start = system_clock::now();

	vector<int> v = { 23, 87, 65, 12, 57, 32, 99, 81 };
	int size = v.size(), pos = size / 2;
	int M = 32, lt = 0, rt, mid, tmp;

	// 정렬해주기
	v = insertSort(v);

	// 원하는 값 찾아주기
	rt = size - 1;
	while (lt <= rt)
	{
		mid = (rt + lt) / 2;
		if (v[mid] == M) break;
		else if (v[mid] > M) rt = mid - 1;
		else if (v[mid] < M) lt = mid + 1;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	My_No42();
//	No42();
//
//	return 0;
//}