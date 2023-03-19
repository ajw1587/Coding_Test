#include <iostream>

using namespace std;

// 자연수 A, B가 공백을 사이에 두고 차례대로 입력
// A부터 B까지의 합을 수식과 함께 출력하시오.
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