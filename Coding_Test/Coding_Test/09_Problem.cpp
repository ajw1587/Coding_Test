#include <iostream>
#include <vector>

using namespace std;

// �ڿ��� N�� �ԷµǸ� 1���� N������ �� ���ڵ��� ����� ������ ����Ͻÿ�.
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