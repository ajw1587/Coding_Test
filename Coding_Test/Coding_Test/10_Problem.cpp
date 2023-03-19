#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// N���� �ڿ����� �ԷµǸ� �� �ڿ����� �ڸ����� ���� ���ϰ�, �� ���� �ִ��� �ڿ����� ����Ͻÿ�.

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
	// ���� ����
	int max = -1;
	int max_idx = -1;
	int max_tmp;

	string N;
	string s_nums;
	vector<int> nums;

	// ���ڿ� �޾ƿ���
	cin >> N;
	cin.ignore();
	getline(cin, s_nums);

	// ���ڿ� int ������ �ٲ��ֱ�
	nums = s_split(s_nums, ' ');
	
	// max ���ϱ�
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