#include <iostream>

using namespace std;

// �ڿ��� N�� �ԷµǸ� 1���� N������ �ڿ����� ���̿� ������ �� ���ڴ� � �ΰ�
// ex) 15 -> 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5 : 21��
int No11()
{
	int N, num, answer = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		num = i;
		while (num)
		{
			answer++;
			num = num / 10;
		}
	}

	cout << answer << endl;

	return 0;
}

//int main()
//{
//	No11();
//
//	return 0;
//}