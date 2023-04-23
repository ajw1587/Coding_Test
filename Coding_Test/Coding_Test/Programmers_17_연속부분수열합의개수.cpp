#include <iostream>
#include <chrono>
#include <vector>
#include <map>

using namespace std;
using namespace chrono;

// ���� �κ� ���� ���� ����
// https://school.programmers.co.kr/learn/courses/30/lessons/131701
int No()
{
	system_clock::time_point start = system_clock::now();

	int answer = 0;
	vector<int> elements =
	{ 7, 9, 1, 1, 4 };

	// ���� ���� 1d�� ������ֱ�
	vector<int> two_elements(elements);
	two_elements.insert(two_elements.end(), elements.begin(), elements.end() - 1);

	// Check List
	map<int, int> ch_elements;

	// ������ �����ֱ�
	for (int i = 0; i < elements.size(); i++)
	{
		int sum = 0;
		for (int j = i; j < i + elements.size(); j++)
		{
			sum += two_elements[j];
			if (ch_elements[sum] == 0) answer++;
			ch_elements[sum]++;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No();

	return 0;
}