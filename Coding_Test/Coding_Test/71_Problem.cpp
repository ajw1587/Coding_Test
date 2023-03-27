#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 송아지 찾기 (BFS : 상태트리 탐색)
// 현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다. 
// 현수의 위치와 송아지의 위치가 직선상의 좌표 점으로 주어지면
// 현수는 현재 위치에서 송아지의 위치까지 다음과 같은 방법으로 이동한다.
// 현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 
// 앞으로 1, 뒤로 1, 앞으로 5를 이동할 수 있다.
// 최소 몇 번의 점프로 현수가 송아지의 위치까지 갈 수 있는지 
// 구하는 프로그램을 작성하세요.
//
// ex) 
// 입력 : S(현수의 위치) = 5, E(송아지의 위치) = 14
// 출력 : 3
int No71()
{
	system_clock::time_point start = system_clock::now();

	int S = 5, E = 14, pos = 0;
	vector<int> dis(10001, 100001);
	vector<int> move = { 1, -1, 5 };
	queue<int> Q;

	dis[S] = 0;
	Q.push(S);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for (int i = 0; i < move.size(); i++)
		{
			pos = x + move[i];
			if (pos < 0 || pos > 10000) continue;
			dis[pos] = (dis[pos] > dis[x] + 1) ? dis[x] + 1 : dis[pos];
			if (pos == E)
			{
				cout << dis[pos] << endl;
				exit(0);
			}
			Q.push(pos);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No71();

	return 0;
}