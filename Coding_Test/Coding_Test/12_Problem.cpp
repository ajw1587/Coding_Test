#include <iostream>

using namespace std;

// ������ 11���� ���������� ū ���� ���������� ��Ȳ
// ���ڸ� ���� 9��
// ���ڸ� ���� 90�� (10 ~ 99)
// ���ڸ� ���� 900�� (100 ~ 999)
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