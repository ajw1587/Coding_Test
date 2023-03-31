#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// SEND+MORE=MONEY ��� ������ ������� �ֽ��ϴ�.
// �� ������� ���ϴ� ���α׷��� �ۼ��ϼ���.
// ������̶� ���� ������ ��������,
// � ������ �� ���ڵ��� Ư�� ���ڷ� �ٲٸ� 
// �� ���ڰ� � �������� ���ߴ� �����̴�.
// [D, E, M, N, O, R, S, Y]
int send(vector<int> res)
{
	return res[6] * 1000 + res[1] * 100 + res[3] * 10 + res[0];
}

int more(vector<int> res)
{
	return res[2] * 1000 + res[4] * 100 + res[5] * 10 + res[1];
}

int money(vector<int> res)
{
	return res[2] * 10000 + res[4] * 1000 + res[3] * 100 + res[1] * 10 + res[7];
}

void DFS(int idx, vector<int> &res, vector<bool> &ch)
{
	if (idx == 8)
	{
		if (send(res) + more(res) == money(res))
		{
			if (res[2] == 0 || res[6] == 0) return;
			printf("     %d %d %d %d\n", res[6], res[1], res[3], res[0]);
			printf("   + %d %d %d %d\n", res[2], res[4], res[5], res[1]);
			printf("   -----------------\n");
			printf("   %d %d %d %d %d\n", res[2], res[4], res[3], res[1], res[7]);
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (ch[i] == 0)
			{
				res[idx] = i;
				ch[i] = 1;
				DFS(idx + 1, res, ch);
				ch[i] = 0;
			}
		}
	}
}

int No83()
{
	system_clock::time_point start = system_clock::now();

	// ���� Ȯ�ο�
	// [D, E, M, N, O, R, S, Y]
	vector<int> res(8);

	// üũ��
	vector<bool> ch(10, 0);
	int idx = 0;

	// DFS ����
	DFS(idx, res, ch);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No83();

	return 0;
}