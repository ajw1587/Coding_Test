#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 석차 구하기
// N명의 학생의 수학 점수가 입력되면 각 학생의 석차를 입력된 순서대로 출력하시오.
int No25()
{
	system_clock::time_point start = system_clock::now();

	int N = 5, max = 0;
	vector<int> points = { 90, 85, 92, 95, 90 };
	vector<int> p_points(N, 1);

	for (int i = 0; i < points.size(); i++)
	{
		int num = points[i];
		for (int j = 0; j < points.size(); j++)
		{
			if (num < points[j])
			{
				p_points[i]++;
			}
		}
	}

	for (int i = 0; i < p_points.size(); i++)
	{
		cout << p_points[i] << ' ';
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No25();
//
//	return 0;
//}