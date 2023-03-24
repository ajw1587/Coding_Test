#include <iostream>
#include <chrono>
#include <vector>
#include <stack>
#include <string>

using namespace std;
using namespace chrono;

// 기차 운행 (Stack 응용)
// A도시에서 출발한 기차는 B도시로 도착한다.
// 그런데 도로 중간에 T자형 교차로가 있어 출발한 기차의 도착 순서를 조정할 수 있다.
// 교차로에서는 다음과 같은 두 개의 작업을 합니다.
// 
// p 작업 : A도시에서 오는 기차를 교차로에 넣는다.
// o 작업 : 교차로에 들어온 가장 최근 기차를 B도시로 보낸다.
// 
// 만약 2, 1, 3 기차 번호 순으로 A도시에서 출발하더라고 B도시에는 T교차로를 이용하여
// 1, 2, 3 순으로 도착 할 수 있습니다.
// 그 작업 P, P, O, O, P, O 순으로 작업하면 B도시에 1, 2, 3 순으로 도착합니다.
// 1부터 N까지 번호를 가진 기차가 A도시에서 어떤 순으로 출발하든, B도시에 번호순으로 도착하도록
// 하는 교차로 작업을 출력하시오.
// 불가능하면 impossible 이라고 출력하시오.
// 
int No55()
{
	system_clock::time_point start = system_clock::now();

	int N = 3, check = 1;
	int idx = 0;
	vector<int> trains = { 2, 1, 3 };
	stack<int> buffer;
	string answer;

	for (int i = 0; i < N; i++)
	{
		buffer.push(trains[i]);
		answer.push_back('P');
		while (!buffer.empty() && buffer.top() == check)
		{
			buffer.pop();
			answer.push_back('O');
			check++;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No55();

	return 0;
}