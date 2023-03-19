#include <iostream>
#include <vector>

using namespace std;

// 자연수 N이 입력되면 1부터 N까지의 각 숫자들의 약수의 개수를 출력하시오.
int My_No09()
{
	int answer = 0;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				answer++;
			}
		}
		cout << answer << ' ';
		answer = 0;
	}

	return 0;
}

int No09()
{
	int N;
	cin >> N;
	vector<int> answer(N+1, 0);

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j += i)
		{
			answer[j]++;
		}
	}

	for (int i = 1; i < answer.size(); i++)
	{
		cout << answer[i] << ' ';
	}

	return 0;
}

//int main()
//{
//	No09();
//
//	return 0;
//}