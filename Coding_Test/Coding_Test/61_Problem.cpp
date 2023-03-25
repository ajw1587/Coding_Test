#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// Ư�� �� ����� (DFS : MS ���ͺ�)
// N���� ���ҷ� ������ �ڿ��� ������ �־�����,
// ������ ���ҿ� '+', '-' ������ ����Ͽ� Ư�� ���� M�� ����� ��찡
// �� ���� �ִ��� ����Ͻÿ�.
// 
// ex)
// �Է� : {2, 4, 6, 8}, M = 12
// �� 4����
//

int N = 4, M = 12;
vector<int> a = { 2, 4, 6, 8 };
int cnt = 0;

void DFS(int idx, int res)
{
	if (idx >= N)
	{
		if (res == M) cnt++;
		return;
	}
	else
	{
		DFS(idx + 1, res + a[idx]);
		DFS(idx + 1, res - a[idx]);
		DFS(idx + 1, res);
	}
}

int No61()
{
	system_clock::time_point start = system_clock::now();

	int idx = 0, res = 0;
	DFS(idx, res);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No61();

	return 0;
}