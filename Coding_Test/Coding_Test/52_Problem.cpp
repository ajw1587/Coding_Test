#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// Ugly Numbers (Three Pointer Algorithm)
// � ���� ���μ����� ���� �� �� ���μ��� 2 �Ǵ� 3 �Ǵ� 5�θ� �̷���� ����
// Ugly Number��� �θ��ϴ�.
// Ugly Number�� ���ʴ�� �����
// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ... �Դϴ�.
// ���� 1�� Ugly Number�� ù ��° ���� �մϴ�.
// �ڿ��� N�� �־����� Ugly Number�� ���ʷ� ���� �� N��° Ugly Number�� ���Ͻÿ�.
// 3 <= N <= 1500
int No52()
{
	system_clock::time_point start = system_clock::now();

	int N = 10;
	int p2 = 1, p3 = 1, p5 = 1;
	int tmp = 2147000000;
	bool flag2 = false, flag3 = false, flag5 = false;
	vector<int> n(N + 1, 0);

	n[1] = 1;
	for (int i = 2; i < n.size(); i++)
	{
		if (n[p2] * 2 < n[p3] * 3) tmp = n[p2] * 2;
		else tmp = n[p3] * 3;
		if (n[p5] * 5 < tmp) tmp = n[p5] * 5;

		if (tmp == n[p2] * 2) p2++;
		if (tmp == n[p3] * 3) p3++;
		if (tmp == n[p5] * 5) p5++;

		n[i] = tmp;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No52();
//
//	return 0;
//}