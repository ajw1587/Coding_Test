#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

// 첫 줄 N명의 학생
// 두번째 줄 N개의 수 (1~1000)
// 각 숫자의 1부터 숫자까지의 합
int My_No17()
{
	system_clock::time_point start = system_clock::now();
	vector<int> sum(1001, 0);
	int sum_tmp = 0;
	for (int i = 1; i < sum.size(); i++)
	{
		sum_tmp += i;
		sum[i] = sum_tmp;
	}

	// 학생들의 값 받아오기 및 판단하기
	int N = 3;
	vector<int> NUM = { 10, 20, 100 };
	vector<int> RESULT = { 55, 350, 5050 };

	for (int i = 0; i < N; i++)
	{
		if (sum[NUM[i]] == RESULT[i]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);

	cout << "My_No17() 소요 시간 : " << micro.count() << endl;	// 258

	return 0;
}

int No17()
{
	system_clock::time_point start = system_clock::now();
	// 학생들의 값 받아오기 및 판단하기
	int N = 3, TRUE_RESULT = 0;
	vector<int> NUM = { 10, 20, 100 };
	vector<int> RESULT = { 55, 350, 5050 };

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= NUM[i]; j++)
		{
			TRUE_RESULT += j;
		}

		if (TRUE_RESULT == RESULT[i]) cout << "YES" << endl;
		else cout << "NO" << endl;

		TRUE_RESULT = 0;
	}
	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);

	cout << "No17() 소요 시간 : " << micro.count() << endl;	// 124

	return 0;
}

//int main()
//{
//	My_No17();
//	No17();
//
//	return 0;
//}