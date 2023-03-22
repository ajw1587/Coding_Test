#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 마구간 정하기 (이분 검색 응용)
// N개의 마구간이 수직선상에 있다. 각 마구간의 좌표는 x1, x2, x3, ...이다.
// 현수는 C마리의 말을 가지고 있는데, 말들은 가까이 있는 것을 좋아하지 않는다.
// 각 마구간에는 한 마리의 말만 넣을 수 있고, 가장 가까운 두 말의 거리가 최대가 되게 말을 배치하시오.
// N개 마구간, C마리의 말
static vector<int> insertSort(vector<int> v)
{
	int temp = 0, j = 0;

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

int No44()
{
	system_clock::time_point start = system_clock::now();

	int N = 5, C = 3;
	vector<int> place = { 1, 2, 8, 4, 9 };
	int l, r, m, pos, dis = 0, cnt = 1, s = place.size();
	int ans = -1;

	// place 정렬해주기
	place = insertSort(place);

	// 거리 찾아주기
	l = 1, pos = 0;
	r = place[place.size() - 1];
	while (l <= r)
	{
		m = (l + r) / 2;	// 거리
		cnt = 1;
		pos = 0;
		for (int i = 1; i < s - 1; i++)
		{
			dis = place[i] - place[pos];
			if (dis >= m)
			{
				pos = i;
				cnt++;
			}
		}

		if (cnt < 3) r = m - 1;
		else if (cnt > 3) l = m + 1;
		else
		{
			ans = (ans < m) ? m : ans;
			l = m + 1;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No44();
//
//	return 0;
//}