#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <map>

using namespace std;
using namespace chrono;

// 할인 행사
// https://school.programmers.co.kr/learn/courses/30/lessons/131127
int No()
{
	system_clock::time_point start = system_clock::now();

	int answer = 0;
	vector<string> want =
	{ "banana", "apple", "rice", "pork", "pot" };
	vector<int> number =
	{ 3, 2, 2, 2, 1 };
	vector<string> discount =
	{ "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };

	// want 정리해주기
	int wants_total = 0;
	map<string, int> ch_wants;
	for (int i = 0; i < want.size(); i++)
	{
		wants_total += number[i];
		ch_wants.insert(make_pair(want[i], number[i]));
	}

	// Check 해주기
	int copy_total = 0;
	bool flag = true;
	map<string, int> copy_ch;
	for (int i = 0; i <= discount.size() - wants_total; i++)
	{
		copy_total = wants_total;
		flag = true;
		copy_ch = ch_wants;
		for (int j = i; j < i + wants_total; j++)
		{
			string item = discount[j];
			if (copy_ch[item] == 0)
			{
				flag = false;
				break;
			}
			else
			{
				copy_total--;
				copy_ch[item]--;
			}
		}
		if (flag && copy_total == 0) answer++;
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