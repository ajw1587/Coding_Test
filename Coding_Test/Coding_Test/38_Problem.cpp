#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// Inversion Sequence
// 1부터 n까지의 수를 한 번씩만 사용하여 이루어진 수열이 있을 때,
// 1부터 n까지 각각의 수 앞에 놓여 있는 자신보다 큰 수들의 개수를 수열로 표현한 것을 Inversion Sequence라고 한다.
// 예를 들어,
// 4, 8, 6, 2, 5, 1, 3, 7
// 1 앞에 놓인 1보다 큰 수는 4, 8, 6, 2, 5 이렇게 5개
// 2 앞에 놓인 2보다 큰 수는 4, 8, 6 이렇게 3개
// 3 앞에 놓인 3보다 큰 수는 4, 8, 6, 5 이렇게 4개
// 최종 Inversion Sequence는 5, 3, 4, 0, 2, 1, 1, 0 이 된다.
// Inversion Sequence가 주어질때 원래의 수열을 구하시오.
int My_No38()
{
	system_clock::time_point start = system_clock::now();

	int size = 8;	// 숫자는 1 ~ 8 까지 사용
	int temp, idx, num = -1, cnt = 0;
	vector<int> is = { 5, 3, 4, 0, 2, 1, 1, 0 };
	vector<int> ans(size, 0);

	for (int i = is.size() - 1; i >= 0; i--)
	{
		num = i + 1;
		cnt = 0;
		// num이 들어갈 idx 찾기
		for (idx = 0; idx < ans.size(); idx++)
		{
			if (cnt == is[i])
			{
				break;
			}
			if (ans[idx] > num)
			{
				cnt++;
			}
		}

		// 들어갈 자리 정렬해주기
		for (int i = ans.size()-1; i > idx; i--)
		{
			temp = ans[i];
			ans[i] = ans[i - 1];
			ans[i - 1] = temp;
		}
		ans[idx] = num;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int No38()
{
	system_clock::time_point start = system_clock::now();

	int size = 8;	// 숫자는 1 ~ 8 까지 사용
	int temp, pos, j, cnt = 0;
	vector<int> is = { -99, 5, 3, 4, 0, 2, 1, 1, 0 };
	vector<int> os(size+1, 0);

	for (int i = size; i >= 1; i--)
	{
		pos = i;
		for (j = 1; j <= is[i]; j++)
		{
			os[pos] = os[pos + 1];
			pos++;
		}
		os[pos] = i;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	My_No38();	// 72
//	No38();		// 5
//
//	return 0;
//}