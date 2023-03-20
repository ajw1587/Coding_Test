#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 측정치가 M값을 넘으면 세대호수와 작은 경보음이 관리실 모니터에서 울린다.
// 한 세대의 N초 동안의 실시간 측정치가 주어지면 최대 연속으로 경보음이 울린 시간을 구하시오.
// ex) 10 90
// ex) 23 17 120 34 112 136 123 23 25 113
// ex) output = 3
int No18()
{
	system_clock::time_point start = system_clock::now();

	int N = 90, ans = -1, ans_tmp = 0;
	bool flag = true;
	vector<int> N_vec = { 23, 17, 120, 34, 112, 136, 123, 23, 25, 113 };

	for (int i = 0; i < N_vec.size(); i++)
	{
		if (N_vec[i] < N)
		{
			ans_tmp = 0;
		}
		else
		{
			ans_tmp++;
			ans = (ans < ans_tmp) ? ans_tmp : ans;
		}
	}
	cout << ans << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No18();
//
//	return 0;
//}