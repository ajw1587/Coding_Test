#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 뮤직 비디오 (이분검색 응용 : 결정 알고리즘) -> 답을 미리 지정해두고 검수 진행
// 총 N개의 곡
// M개의 DVD
// ex)
// 9, 3 -> 9개의 곡을 3개의 DVD에
// 1, 2, 3, 4, 5, 6, 7, 8, 9 개의 곡 (1분, 2분, 3분, ...)
// 출력 : 17
int No43()
{
	system_clock::time_point start = system_clock::now();

	int N = 9, M = 9;
	vector<int> songs = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int lt = 0, rt = N - 1, mid = -1, cnt = 0, temp = 0, ans = 9999;
	int sum = 0, max = -123;

	for (int i = 1; i <= N; i++)
	{
		sum += i;
		max = (max < i) ? i : max;
	}

	lt = 1;
	rt = sum;
	while (lt <= rt)
	{
		mid = (lt + rt) / 2;	// time
		cnt = 0, temp = 0;
		for (int i = 0; i < N; i++)
		{
			if (temp + songs[i] > mid)
			{
				cnt++;
				temp = songs[i];
				if (i == N - 1) cnt++;
			}
			else temp += songs[i];
		}

		if (cnt <= M && mid >= max)
		{
			ans = mid;
			rt = mid - 1;
		}
		else lt = mid + 1;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No43();
//
//	return 0;
//}