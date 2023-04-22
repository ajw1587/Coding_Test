#include <iostream>
#include <chrono>
#include <vector>
#include <stack>

using namespace std;
using namespace chrono;

// 택배 상자
// https://school.programmers.co.kr/learn/courses/30/lessons/131704
int No()
{
	system_clock::time_point start = system_clock::now();

	int answer = 0;
	vector<int> order =
	{ 4, 3, 1, 2, 5 };
	//vector<int> order =
	//{ 5, 4, 3, 2, 1 };
	//1, 2, 3, 4, 5

	int order_idx = 0;
	stack<int> sub_container;
	for (int i = 1; i <= order.size(); i++)
	{
		//int order_num = order[order_idx];
		//if (order_num == i)
		//{
		//	order_idx++;
		//	answer++;
		//}
		//else  // order_num != i
		//{
		//	sub_container.push(i);
		//}

		sub_container.push(i);
		int order_num = order[order_idx];
		while (!sub_container.empty() && sub_container.top() == order_num)
		{
			sub_container.pop();
			answer++;
			order_idx++;
			if (order_idx >= order.size()) break;
			order_num = order[order_idx];
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No();

	return 0;
}