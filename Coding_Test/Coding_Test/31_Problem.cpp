#include <iostream>
#include <chrono>
#include <vector>
#include <string>

using namespace std;
using namespace chrono;

// 탄화수소 질량
// '1' : 49
int No31()
{
	system_clock::time_point start = system_clock::now();

	int c = 0, h = 0, idx = 0, answer = 0;
	string input;
	cin >> input;

	// C 개수 구해주기
	if (input[1] == 'H')
	{
		c++;
		idx = 1;
	}
	else
	{
		for (int i = 1; input[i] != 'H'; i++)
		{
			c = c * 10 + input[i]-48;
			idx = i+1;	// H의 위치
		}
	}

	// H 개수 구해주기
	if (input[input.size() - 1] == 'H')
	{
		h++;
	}
	else
	{
		for (int i = idx+1; i < input.size(); i++)
		{
			h = h * 10 + input[i] - 48;
		}
	}
	answer = 4 * c + 1 * h;
	cout << answer << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No31();
//
//	return 0;
//}