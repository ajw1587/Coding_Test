#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ī����� ���ϰ� �ִ� ������ ���ú��� N+1��° �Ǵ� �� �ް��� ���� ���ؼ�, 
// ���� N�� ���� �ִ��� ���� ����� �ؼ� �ް��� �˳��� ����� �ް��� ������ �Ѵ�.
// ������ �ٴϴ� ȸ�翡 �Ϸ翡 �ϳ��� ���� �ٸ� ����� ����� ����Ǿ� �ִ�.
// ������ ����� ����� �Ϸ��ϴµ� �ɸ��� ���� T��
// ����� ���� �� ���� �� �ִ� �ݾ� P�� �̷���� �ִ�.
// ���� N = 7�̰�, �Ʒ��� ���� ������ �����ִٸ�
//   1�� 2�� 3�� 4�� 5�� 6�� 7��
// T  4   2   3   3  2   2   1
// P 20  10  15  20  30  20  10

int answer = 0;

void DFS(int idx, vector<vector<int>> sc, int res)
{
	if (idx == 7)
	{
		answer = (answer < res) ? res : answer;
		return;
	}
	else
	{
		if (idx + sc[idx][0] <= 7) DFS(idx + sc[idx][0], sc, res + sc[idx][1]);
		DFS(idx + 1, sc, res);
	}
}

int No84()
{
	system_clock::time_point start = system_clock::now();

	int N = 7;
	int res = 0;
	vector<vector<int>> sc =
	{{ 4, 20 },
	{ 2, 10 },
	{ 3, 15 },
	{ 3, 20 },
	{ 2, 30 },
	{ 2, 20 },
	{ 1, 10 }};

	DFS(0, sc, res);

	cout << answer << endl;

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No84();

	return 0;
}