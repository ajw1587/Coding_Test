#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// N!의 표현법
// 소수로 표현할 수 있는 방법
int No27()
{
	system_clock::time_point start = system_clock::now();

	// 팩토리얼 구해주기
	int N = 53;
	int tmp = 0, j = 2;
	vector<int> ch(N + 1, 0);

	for (int i = 2; i <= N; i++)
	{
		tmp = i;
		j = 2;
		while (tmp != 1)
		{
			if (tmp % j == 0)
			{
				tmp /= j;
				ch[j]++;
			}
			else j++;
		}
	}

	for (int i = 0; i < ch.size(); i++)
	{
		if (ch[i] != 0) cout << ch[i] << ' ';
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No27();
//
//	return 0;
//}