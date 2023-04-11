#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 회장뽑기 (플로이드-워샬 응용)
// 회원사이에 서로 모르는 사람도 있지만, 몇 사람을 통하면 서로 모두 알 수 있다.
// 각 회원은 다른 회원들과 가까운 정도에 따라 점수를 받게 된다. 
// 예를 들어 어느 회원이 다른 모든 회원과 친구이면, 이 회원의 점수는 1점이다.
// 어느 회원의 점수가 2점이면, 다른 모든 회원이 친구이거나, 친구의 친구임을 말한다.
// 또한, 어느 회원의 점수가 3점이면, 다른 모든 회원이 친구이거나, 
// 친구의 친구이거나, 친국의 친구의 친구임을 말한다.
// 4점, 5점등은 같은 방법으로 정해진다.
// 회장은 회원들 중에서 점수가 가장 작은 사람이 된다.
// 회장의 점수와 회장이 될 수 있는 모든 사람을 찾는 프로그램을 작성하시오.
// 한 줄에 두 개의 회원번호가 있는데, 이것은 두 회원이 서로 친구임을 나타낸다.
int No103()
{
	system_clock::time_point start = system_clock::now();

	int peoples = 5;
		1 2
		2 3
		3 4
		4 5
		2 4
		5 3
		- 1 - 1


	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No103();

	return 0;
}