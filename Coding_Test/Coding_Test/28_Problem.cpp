#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// N!에서 0의 개수
// 자연수 N이 입력되면 N! 값에서 일의 자리부터 연속적으로 0이 몇 개 있는지 구하시오.
// ex) 12 -> 2 출력
// 2와 5의 개수를 구하자.
int No28()
{
	system_clock::time_point start = system_clock::now();

	int N = 12, j = 2, tmp;
	bool flag = false;
	vector<int> temp(6, 0);		// idx 0 : 2, idx 1 : 5
	for (int i = 2; i <= N; i++)
	{
		tmp = i;
		j = 2;
		flag = false;
		while (1)
		{
			if (tmp % j == 0)
			{
				temp[j]++;
				tmp /= j;
			}
			else
			{
				flag = true;
				j = 5;
			}
			if (tmp % j != 0 && flag) break;
		}
	}

	if (temp[2] < temp[5]) cout << temp[2] << endl;
	else cout << temp[5] << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No28();
//
//	return 0;
//}