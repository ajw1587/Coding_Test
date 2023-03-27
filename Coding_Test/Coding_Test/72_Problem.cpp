#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 왕자가 N명 (큐로 해결) 45번 문제와 동일
// 왕자들을 나이 순으로 1번부터 N번까지 차례로 번호를 매긴다.
// 그리고 1번 왕자부터 N번 왕자까지 순서대로 시계방향으로 돌아가며 동그랗게 앉게 한다.
// 그리고 1번 왕자부터 시계방향으로 돌아가며 1부터 시작하여 번호를 외치게 한다.
// 한 왕자가 K(특정 숫자)를 외치면 그 왕자는 공주를 구하러 가는데서 제외되고
// 원 밖으로 나오게 된다.
// 그리고 다음 왕자부터 다시 1부터 시작하여 번호를 외친다.
// 마지막까지 남는 왕자는?
int No72()
{
	system_clock::time_point start = system_clock::now();

	int N = 8, K = 3, cnt = 0, temp = 0;
	vector<int> princes = { 1, 2, 3, 4, 5, 6, 7, 8 };
	queue<int> Q;

	for (int i = 0; i < princes.size(); i++)
	{
		Q.push(princes[i]);
	}

	while (Q.size() != 1)
	{
		temp = Q.front();
		Q.pop();
		cnt++;
		if (cnt == K)
		{
			cnt = 0;
			continue;
		}
		Q.push(temp);
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No72();

	return 0;
}