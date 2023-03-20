#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// Jolly Jumpers
// N개의 정수로 이루어진 수열에 대해 서로 인접해 있는 두 수의 차가 1에서 N-1까지의 값을 모두 가지면
// 그 수열을 유쾌한 점퍼라고 부른다.
// 1, 4, 2, 3 앞 뒤에 있는 숫자 차의 절대 값이 각각 3, 2, 1이므로 유쾌한 점퍼다.
int No24()
{
	system_clock::time_point start = system_clock::now();

	int N = 5, temp = 0;
	vector<int> numbers = { 1, 4, 2, 3, 7 };
	vector<bool> check(N, false);
	check[0] = true;

	for (int i = 0; i < N-1; i++)
	{
		temp = abs(numbers[i + 1] - numbers[i]);

		if (check[temp])
		{
			cout << "NO" << endl;
			return 0;
		}
		else
		{
			check[temp] = true;
		}
	}

	if (find(check.begin(), check.end(), false) != check.end())
	{
		cout << "NO" << endl;
	}
	else cout << "YES" << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No24();
//
//	return 0;
//}