#include <iostream>
#include <string>
#include <vector>
#include "14_Problem.h"

using namespace std;

// N���� �ڿ����� �ԷµǸ� �� �ڿ����� ������ �� �� ������ ���� �Ҽ��̸� �� ���� ����Ͻÿ�.
// ��� ������ �Էµ� ������� ���
int int_reverse(int x)
{
	int temp, idx = 1, answer = 0;

	while (x)
	{
		temp = x % 10;	7;
		answer = answer * 10 + temp;
		x /= 10;
	}
	return answer;
}

bool isPrime(int x)
{
	bool sign = true;
	if (x == 1) return false;

	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			sign = false;
			break;
		}
	}
	return sign;
}

int No14()
{
	int N, num, re_num;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		cout << num << endl;
		re_num = int_reverse(num);
		if (isPrime(re_num)) cout << re_num << endl;
	}

	return 0;
}

//int main()
//{
//	No14();
//
//	return 0;
//}