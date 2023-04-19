#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

// 숫자 카드 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/135807

vector<int> check_num(int a)
{
	vector<int> res;

	for (int i = 2; i <= a; i++)
	{
		if (a % i == 0) res.push_back(i);
	}

	return res;
}

int get_result(vector<int> numbers, vector<int> arrayA, vector<int> arrayB)
{
	int answer = 0;
	int a_check = 0, b_check = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		int num = numbers[i];
		a_check = 0; b_check = 0;
		for (int j = 0; j < arrayA.size(); j++)
		{
			if (arrayA[j] % num != 0)
			{
				a_check++;
			}
		}

		for (int j = 0; j < arrayB.size(); j++)
		{
			if (arrayB[j] % num != 0)
			{
				b_check++;
			}
		}

		if (a_check == 0 && b_check != 0 && b_check == arrayB.size()) answer = num;
		if (a_check != 0 && b_check == 0 && a_check == arrayA.size()) answer = num;
	}

	return answer;
}

int No()
{
	system_clock::time_point start = system_clock::now();
	int answer = 0;
	int answer1 = 0;
	int answer2 = 0;

	vector<int> arrayA = { 14, 35, 119 };
	vector<int> arrayB = { 18, 30, 102 };
	
	//vector<int> arrayA = { 10, 17 };
	//vector<int> arrayB = { 5, 20 };
	
	//vector<int> arrayA = { 10, 20 };
	//vector<int> arrayB = { 5, 17 };
	
	//vector<int> arrayA = { 10, 20 };
	//vector<int> arrayB = { 5, 17, 20 };

	vector<int> numbers = check_num(arrayA[0]);
	answer1 = get_result(numbers, arrayA, arrayB);

	numbers = check_num(arrayB[0]);
	answer2 = get_result(numbers, arrayA, arrayB);

	answer = max(answer1, answer2);

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