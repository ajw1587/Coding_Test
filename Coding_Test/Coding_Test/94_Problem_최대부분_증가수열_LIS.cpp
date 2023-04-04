#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 최대 부분 증가수열
// N개의 자연수로 이루어진 수열이 주어졌을 때,
// 그 중에서 가장 길게 증가하는(작은 수에서 큰 수로) 원소들의 집합을 찾는 프로그램을 작성하라.
// 예를 들어, 원소가 2, 7, 5, 8, 6, 4, 7, 12, 3 이면 가장 길게 증가하도록 원소들을 
// 차례대로 뽑아내면 2, 5, 6, 7, 12를 뽑아내어 길이가 5인 최대 부분 증가수열을 만들 수 있다.
int No94()
{
	system_clock::time_point start = system_clock::now();

	int N = 8;
	vector<int> a = { 5, 3, 7, 8, 6, 2, 9, 4 };
	vector<int> dy(N, 0);
	int res = 0;

	dy[0] = 1;
	for (int i = 1; i < dy.size(); i++)
	{
		for (int j = i-1; j >= 0; j--)
		{
			if (a[i] > a[j] && dy[i] < dy[j] + 1)
			{
				dy[i] = dy[j] + 1;
				if (res < dy[i]) res = dy[i];
			}
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No94();

	return 0;
}