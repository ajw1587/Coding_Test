#include <iostream>

using namespace std;

// 자연수 N이 입력되면 1부터 N까지의 소수의 개수를 출력하시오.
int No15()
{
	bool sign = true;
	int N, answer = 0;
	scanf("%d", &N);

	if (N == 1)
	{
		cout << answer << endl;
		return answer;
	}

	answer = 0;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j*j <= i; j++)
		{
			if ((i % j) == 0)
			{
				sign = false;
				break;
			}
		}

		if (sign) answer++;
		sign = true;
	}

	cout << answer << endl;

	return answer;
}

int main()
{
	No15();

	return 0;
}