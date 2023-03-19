#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력하시오.

vector<int> s_split(string s_nums, char del)
{
	vector<int> answer;
	stringstream ss(s_nums);
	string temp;

	while (getline(ss, temp, del))
	{
		answer.push_back(stoi(temp));
	}

	return answer;
}

int digit_sum(int num)
{
	int temp;
	int answer = 0;

	while (num)
	{
		answer += num % 10;
		num = num / 10;
	}

	return answer;
}

int No10()
{
	// 변수 선언
	int max = -1;
	int max_idx = -1;
	int max_tmp;

	string N;
	string s_nums;
	vector<int> nums;

	// 문자열 받아오기
	cin >> N;
	cin.ignore();
	getline(cin, s_nums);

	// 문자열 int 형으로 바꿔주기
	nums = s_split(s_nums, ' ');
	
	// max 구하기
	for (int i = 0; i < nums.size(); i++)
	{
		max_tmp = digit_sum(nums[i]);
		if (max_tmp > max)
		{
			max = max_tmp;
			max_idx = i;
		}
		else if (max_tmp == max)
		{
			max_idx = (nums[i] > nums[max_idx]) ? i : max_idx;
		}
	}

	cout << nums[max_idx] << endl;

	return 0;
}

//int main()
//{
//	No10();
//
//	return 0;
//}