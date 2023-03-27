#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// �ִ��� (priority_queue : �켱���� ť)
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No73();

	return 0;
}