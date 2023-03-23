#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 정면에서 본 단면과 오른쪽 측면에서 본 단면을 주고
// 최대 블록 개수를 사용하여 정면과 오른쪽 측면에서 본 모습으로 블록을 쌓으라 했습니다.
// 블록을 쌓는데 사용해야 할 최대 개수를 출력하시오.
// 첫 줄에는 블록의 크기 N
// 두 번째 줄에는 정면에서의 높이 정보
// 세 번째 줄에는 오른쪽 측면 높이 정보
int No49()
{
	system_clock::time_point start = system_clock::now();

	int N = 4;
	vector<int> front = { 2, 0, 3, 1 };
	vector<int> right = { 1, 1, 2, 3 };
	int f_sum = -1, r_sum = -1, res = 0;

	while (f_sum != 0 && r_sum != 0)
	{
		f_sum = 0;
		r_sum = 0;
		for (int i = 0; i < front.size(); i++)
		{
			if (front[i] > 0)
			{
				f_sum += 1;
				front[i]--;
			}
		}

		for (int i = 0; i < right.size(); i++)
		{
			if (right[i] > 0)
			{
				r_sum += 1;
				right[i]--;
			}
		}

		res = res + f_sum * r_sum;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No49();
//
//	return 0;
//}