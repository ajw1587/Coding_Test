#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ����ġ�� M���� ������ ����ȣ���� ���� �溸���� ������ ����Ϳ��� �︰��.
// �� ������ N�� ������ �ǽð� ����ġ�� �־����� �ִ� �������� �溸���� �︰ �ð��� ���Ͻÿ�.
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
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No18();
//
//	return 0;
//}