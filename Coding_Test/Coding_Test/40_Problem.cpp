#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 교집합 (투포인터 알고리즘)
// 두 집합 A, B가 주어지면 두 집합의 교집합을 출력하시오.
// ex)
// 2, 7, 10, 5, 3		-> N개의 수
// 3, 10, 5, 17, 12		-> M개의 수
// 정답 : 3, 5, 10

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

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << ' ';
		}
		cout << endl;
	}

	return v;
}

int No40()
{
	system_clock::time_point start = system_clock::now();

	vector<int> v1 = { 2, 7, 10, 5, 3 };
	vector<int> v2 = { 3, 10, 5, 17, 12 };
	vector<int> ans(100, 0);
	int p1 = 0, p2 = 0, p3 = 0;

	// 정렬 먼저 해주기
	// 삽입 정렬 구현해보자!
	v1 = insertSort(v1);
	v2 = insertSort(v2);
	while (p1 < v1.size() && p2 < v2.size())
	{
		if (v1[p1] > v2[p2]) p2++;
		else if (v1[p1] < v2[p2]) p1++;
		else
		{
			ans[p3++] = v1[p1];
			p1++;
			p2++;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No40();
//
//	return 0;
//}