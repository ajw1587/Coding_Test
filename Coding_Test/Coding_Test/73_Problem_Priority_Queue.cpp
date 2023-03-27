#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 최대힙 (priority_queue : 우선순위 큐)
int No73()
{
	system_clock::time_point start = system_clock::now();

	vector<int> input = { 5, 3, 6, 0, 5, 0, 2, 4, 0, -1 };
	priority_queue<int> pQ;
	int i = 0;
	while (true)
	{
		if (input[i] == -1) break;
		if (input[i] == 0)
		{
			if (pQ.empty()) cout << -1 << endl;
			else
			{
				cout << pQ.top() << endl;
				pQ.pop();
			}
		}
		else
		{
			pQ.push(input[i]);
		}
		i++;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No73();

	return 0;
}