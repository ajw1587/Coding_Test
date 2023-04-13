#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 연속된 부분 수열의 합
// https://school.programmers.co.kr/learn/courses/30/lessons/178870

int k = 7;
//int k = 6;
int len = 2147000000;
int s = 0;
int e = 0;
vector<int> sequence = { 1, 2, 3, 4, 5 };
//vector<int> sequence = { 2, 2, 2, 2, 2 };

// 시간초과
void DFS(int idx, int sum, int l, int st)
{
	if (sum == k)
	{
		if (len > l)
		{
			len = l;
			s = st;
			e = idx - 1;
		}

	}
	else
	{
		if (sum > k) return;
		if (idx >= sequence.size()) return;
		DFS(idx + 1, sum + sequence[idx], l + 1, st);
	}
}

int DFSNo()
{
	system_clock::time_point start = system_clock::now();

	// 시간초과
	for (int i = 0; i < sequence.size(); i++)
	{
		DFS(i, 0, 0, i);
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int No()
{
	system_clock::time_point start = system_clock::now();

	int l = 0, r = 0, s = 0, e = 0;
	int length = 2147000000;
	int n = sequence.size();	// 5
	//int sum = sequence[0];
	int sum = sequence[0];

	while (true)
	{
		if (sum == k)
		{
			int tmp = r - l + 1;
			if (tmp < length)
			{
				s = l;
				e = r;
				length = tmp;
			}
		}

		if (r >= n && l >= n) break;

		if (sum <= k && r < n)
		{
			r++;
			if (r < n) sum += sequence[r];
		}
		else
		{
			if (l < n) sum -= sequence[l];
			l++;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	// 시간초과
	DFSNo();

	No();

	return 0;
}