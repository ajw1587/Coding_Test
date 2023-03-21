#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// Special Sort (구글)
// N개의 정수를 정렬하시오.
// 음의 정수는 앞쪽에 양의정수는 뒷쪽에 있어야 한다.
// 단, 입력된 순서는 변경되면 안된다.
// ex) 1, 2, 3, -3, -2, 5, 6, -6
// ->  -3, -2, -6, 1, 2, 3, 5, 6
int My_No35()
{
	system_clock::time_point start = system_clock::now();

	vector<int> p = { 1, 2, 3, -3, -2, 5, 6, -6 };
	int temp = -9999, idx = 0;

	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] >= 0) continue;
		for (int j = i; j > idx; j--)
		{
			temp = p[j - 1];
			p[j - 1] = p[j];
			p[j] = temp;
		}
		idx++;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;		// 3189
	return 0;
}

int No35()
{
	system_clock::time_point start = system_clock::now();

	vector<int> p = { 1, 2, 3, -3, -2, 5, 6, -6 };

	for (int i = 0; i < p.size() - 1; i++) {
		for (int j = 0; j < p.size() - i - 1; j++) {
			if (0 < p[j] && p[j + 1] < 0) {
				int tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}

		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;		// 3329
	return 0;
}

//int main()
//{
//	No35();		// 3329
//	cout << endl;
//	My_No35();	// 3189
//
//	return 0;
//}