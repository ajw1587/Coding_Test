#include <iostream>

using namespace std;

// 문제는 11번과 동일하지만 큰 수가 들어왔을때의 상황
// 한자리 수는 9개
// 두자리 수는 90개 (10 ~ 99)
// 세자리 수는 900개 (100 ~ 999)
int No12()
{
	int answer = 0, i = 1;
	int N, sum = 0, location = 9;
	scanf("%d", &N);

	while (sum + location < N)
	{
		sum += location;
		answer += (location * i);
		i++;
		location *= 10;
	}

	answer += ((N - sum) * i);

	cout << answer << endl;

	return 0;
}

//int main()
//{
//	No12();
//
//	return 0;
//}