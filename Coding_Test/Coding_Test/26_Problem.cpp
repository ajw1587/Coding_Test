#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 마라톤
// 자기보다 앞에 달리고 있는 선수들 중 평소 실력이 자기보다 좋은 선수는 앞지를 수 없다.
// 자기보다 평소 실력이 좋지 않은 선수는 앞지를 수 있다.
// 평소 실력은 점수로 주어진다.
// 2, 8, 10, 7, 1, 9, 4, 15
// 답 : 1, 1, 1, 3, 5, 2, 5, 1
// 
// my: 1 1 1 3 5 2 5 1
int No26()
{
	system_clock::time_point start = system_clock::now();

	vector<int> skill = { 2, 8, 10, 7, 1, 9, 4, 15 };
	vector<int> answer(skill.size(), 1);
	int count = 1;

	for (int i = skill.size()-1; i > 0; i--)
	{
		for (int j = i - 1; j > -1; j--)
		{
			if (skill[i] < skill[j])  count++;
		}
		answer[i] = count;
		count = 1;
	}

	for (int i = 0; i < answer.size(); i++) cout << answer[i] << ' ';

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No26();
//
//	return 0;
//}