#include <iostream>

using namespace std;

// �ڿ��� N�� �ԷµǸ� 1���� N������ �Ҽ��� ������ ����Ͻÿ�.
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