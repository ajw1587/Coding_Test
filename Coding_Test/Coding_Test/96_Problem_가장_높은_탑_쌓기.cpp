#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 가장 높은 산 쌓기
// 밑면이 정사각형인 직육면체 벽돌들을 사용하여 탑을 쌓고자 한다.
// 탑은 벽돌을 한 개씩 아래에서 위로 쌓으면서 만들어 간다.
// 아래의 조건을 만족하면서 가장 높은 탑을 쌓을 수 있는 프로그램을 작성하시오.
// 
// (조건1)벽돌은 회전시킬 수 없다.즉, 옆면을 밑면으로 사용할 수 없다.
// (조건2)밑면의 넓이가 같은 벽돌은 없으며, 또한 무게가 같은 벽돌도 없다.
// (조건3)벽돌들의 높이는 같을 수도 있다.
// (조건4)탑을 쌓을 때 밑면이 좁은 벽돌 위에 밑면이 넓은 벽돌은 놓을 수 없다.
// (조건5)무게가 무거운 벽돌을 무게가 가벼운 벽돌 위에 놓을 수 없다.

int No96()
{
	system_clock::time_point start = system_clock::now();



	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No96();

	return 0;
}