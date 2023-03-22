#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ������ ���ϱ� (�̺� �˻� ����)
// N���� �������� �������� �ִ�. �� �������� ��ǥ�� x1, x2, x3, ...�̴�.
// ������ C������ ���� ������ �ִµ�, ������ ������ �ִ� ���� �������� �ʴ´�.
// �� ���������� �� ������ ���� ���� �� �ְ�, ���� ����� �� ���� �Ÿ��� �ִ밡 �ǰ� ���� ��ġ�Ͻÿ�.
// N�� ������, C������ ��
static vector<int> insertSort(vector<int> v)
{
	int temp = 0, j = 0;

	for (int i = 1; i < v.size(); i++)
	{
		temp = v[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (temp < v[j]) v[j + 1] = v[j];
			else break;
		}
		v[j + 1] = temp;
	}

	return v;
}

int No44()
{
	system_clock::time_point start = system_clock::now();

	int N = 5, C = 3;
	vector<int> place = { 1, 2, 8, 4, 9 };
	int l, r, m, pos, dis = 0, cnt = 1, s = place.size();
	int ans = -1;

	// place �������ֱ�
	place = insertSort(place);

	// �Ÿ� ã���ֱ�
	l = 1, pos = 0;
	r = place[place.size() - 1];
	while (l <= r)
	{
		m = (l + r) / 2;	// �Ÿ�
		cnt = 1;
		pos = 0;
		for (int i = 1; i < s - 1; i++)
		{
			dis = place[i] - place[pos];
			if (dis >= m)
			{
				pos = i;
				cnt++;
			}
		}

		if (cnt < 3) r = m - 1;
		else if (cnt > 3) l = m + 1;
		else
		{
			ans = (ans < m) ? m : ans;
			l = m + 1;
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No44();
//
//	return 0;
//}