#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// �۾��� ã�� (BFS : ����Ʈ�� Ž��)
// ������ �۾����� �Ҿ���ȴ�. ������ �۾������� ��ġ�����Ⱑ �޷� �ִ�. 
// ������ ��ġ�� �۾����� ��ġ�� �������� ��ǥ ������ �־�����
// ������ ���� ��ġ���� �۾����� ��ġ���� ������ ���� ������� �̵��Ѵ�.
// ������ ��ī�� ������ Ÿ�� ���µ� �� ���� ������ 
// ������ 1, �ڷ� 1, ������ 5�� �̵��� �� �ִ�.
// �ּ� �� ���� ������ ������ �۾����� ��ġ���� �� �� �ִ��� 
// ���ϴ� ���α׷��� �ۼ��ϼ���.
//
// ex) 
// �Է� : S(������ ��ġ) = 5, E(�۾����� ��ġ) = 14
// ��� : 3
int No71()
{
	system_clock::time_point start = system_clock::now();

	int S = 5, E = 14, pos = 0;
	vector<int> dis(10001, 100001);
	vector<int> move = { 1, -1, 5 };
	queue<int> Q;

	dis[S] = 0;
	Q.push(S);
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for (int i = 0; i < move.size(); i++)
		{
			pos = x + move[i];
			if (pos < 0 || pos > 10000) continue;
			dis[pos] = (dis[pos] > dis[x] + 1) ? dis[x] + 1 : dis[pos];
			if (pos == E)
			{
				cout << dis[pos] << endl;
				exit(0);
			}
			Q.push(pos);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No71();

	return 0;
}