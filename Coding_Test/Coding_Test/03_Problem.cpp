#include <iostream>

using namespace std;

// �ڿ��� N�� �־����� �ڿ��� N�� ������� ���� ���İ� �Բ� ����Ͻÿ�.
int No03()
{
	int N, sum = 0;

	cin >> N;
	cout << "1";
	for (int i = 2; i < N; i++)
	{
		if (N % i == 0)
		{
			cout << " + " << i;
			sum += i;
		}
	}
	cout << " = " << sum+1 << endl;

	return 0;
}

//int main()
//{
//	No03();
//
//	return 0;
//}