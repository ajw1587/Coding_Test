#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 오름차순으로 정렬이 된 두 배열이 주어지면 두 배열을 오름차순으로 합쳐 출력하시오.
int My_No39()
{
	system_clock::time_point start = system_clock::now();

	vector<int> v1 = { 1, 3, 5 };
	vector<int> v2 = { 2, 3, 6, 7, 9 };
	vector<int> ans(v1.size() + v2.size(), 0);
	int pos1 = 0, pos2 = 0, i;

	for (i = 0; i < ans.size(); i++)
	{
		if (pos1 >= v1.size() && pos2 < v2.size())
		{
			ans[i] = v2[pos2];
			pos2++;
			continue;
		}
		else if (pos2 >= v2.size() && pos1 < v1.size())
		{
			ans[i] = v1[pos1];
			pos1++;
			continue;
		}

		if (pos1 < v1.size() && pos2 < v2.size())
		{
			if (v1[pos1] < v2[pos2])
			{
				ans[i] = v1[pos1];
				pos1++;
			}
			else
			{
				ans[i] = v2[pos2];
				pos2++;
			}
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int No39()
{
	system_clock::time_point start = system_clock::now();

	vector<int> v1 = { 1, 3, 5 };
	vector<int> v2 = { 2, 3, 6, 7, 9 };
	vector<int> ans(v1.size() + v2.size(), 0);
	int p1 = 0, p2 = 0, p3 = 0;

	while (p1 < v1.size() && p2 < v2.size())
	{
		if (v1[p1] < v2[p2]) ans[p3++] = v1[p1++];
		else ans[p3++] = v2[p2++];
	}

	while (p1 < v1.size()) ans[p3++] = v1[p1++];
	while (p2 < v2.size()) ans[p3++] = v2[p2++];

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	My_No39();		// 28
//	No39();			// 4
//
//	return 0;
//}