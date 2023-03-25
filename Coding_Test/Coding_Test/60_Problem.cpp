#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���� ���� �κ����� (DFS : �Ƹ��� ���ͺ�)
// N���� ���ҷ� ������ �ڿ��� ������ �־�����,
// �� ������ �� ���� �κ� �������� �������� ��,
// �� �κ������� ������ ���� ���� ���� ��찡 �����ϸ� "YES", �׷��� ������ "NO"�� ����Ͻÿ�.
// 
// ex)
// �Է� : 1, 3, 5, 6, 7, 10
// 1, 3, 5, 7 = 6, 10 �� �κ������� ���� �����Ƿ� "YES"

int N = 6;
vector<int> a = { -99, 1, 3, 5, 6, 7, 10 };
int total = 32;
bool flag = false;

void DFS(int L, int sum)
{
	if (flag == true || sum > total / 2) return;
	if (L == N + 1)
	{
		if (sum == (total - sum))
		{
			flag = true;
		}
	}
	else
	{
		DFS(L + 1, sum + a[L]);
		DFS(L + 1, sum);
	}
}

int No60()
{
	system_clock::time_point start = system_clock::now();

	DFS(1, 0);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No60();

	return 0;
}