#include <iostream>

using namespace std;

// �ڿ��� A, B�� ������ ���̿� �ΰ� ���ʴ�� �Է�
// A���� B������ ���� ���İ� �Բ� ����Ͻÿ�.
int No02()
{
	int A, B, sum = 0;

	cin >> A >> B;
	for (int i = A; i < B; i++)
	{
		cout << i << " + ";
		sum += i;
	}
	cout << B << " = ";
	cout << (sum + B);

	return 0;
}

//int main()
//{
//	No02();
//
//	return 0;
//}