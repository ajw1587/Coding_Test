#include <iostream>

using namespace std;

// 자연수 N이 주어지면 자연수 N의 진약수의 합을 수식과 함께 출력하시오.
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