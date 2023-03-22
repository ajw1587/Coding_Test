#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 왕자가 N명
// 왕자들을 나이 순으로 1번부터 N번까지 차례로 번호를 매긴다.
// 그리고 1번 왕자부터 N번 왕자까지 순서대로 시계방향으로 돌아가며 동그랗게 앉게 한다.
// 그리고 1번 왕자부터 시계방향으로 돌아가며 1부터 시작하여 번호를 외치게 한다.
// 한 왕자가 K(특정 숫자)를 외치면 그 왕자는 공주를 구하러 가는데서 제외되고
// 원 밖으로 나오게 된다.
// 그리고 다음 왕자부터 다시 1부터 시작하여 번호를 외친다.
// 마지막까지 남는 왕자는?
int My_No45()
{
	system_clock::time_point start = system_clock::now();

	int N = 8, K = 3;
	vector<int> princes = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<bool> check(N, true);
	int pos = 0, temp = 1, cnt = princes.size();

	while (cnt != 1)
	{
		pos++;
		temp++;

		if (pos >= cnt) pos = 0;

		if (temp == K)
		{
			cnt--;
			princes.erase(princes.begin() + pos);
			temp = 0;
			pos--;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int No45()
{
	system_clock::time_point start = system_clock::now();

	int N = 8, K = 3;
	vector<int> princes(8, 0);
	int pos = 0, bp = 0, cnt = 0;
	
	while (1)
	{
		pos++;
		if (pos >= N) pos = 0;
		if (princes[pos] == 0)
		{
			cnt++;
			if (cnt == K)
			{
				princes[pos] = 1;
				cnt = 0;
				bp++;
			}
		}
		if (bp == N - 1) break;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	My_No45();		// 56
//	No45();			// 6
//
//	return 0;
//}