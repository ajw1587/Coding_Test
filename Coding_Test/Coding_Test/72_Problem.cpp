#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// ���ڰ� N�� (ť�� �ذ�) 45�� ������ ����
// ���ڵ��� ���� ������ 1������ N������ ���ʷ� ��ȣ�� �ű��.
// �׸��� 1�� ���ں��� N�� ���ڱ��� ������� �ð�������� ���ư��� ���׶��� �ɰ� �Ѵ�.
// �׸��� 1�� ���ں��� �ð�������� ���ư��� 1���� �����Ͽ� ��ȣ�� ��ġ�� �Ѵ�.
// �� ���ڰ� K(Ư�� ����)�� ��ġ�� �� ���ڴ� ���ָ� ���Ϸ� ���µ��� ���ܵǰ�
// �� ������ ������ �ȴ�.
// �׸��� ���� ���ں��� �ٽ� 1���� �����Ͽ� ��ȣ�� ��ģ��.
// ���������� ���� ���ڴ�?
int No72()
{
	system_clock::time_point start = system_clock::now();

	int N = 8, K = 3, cnt = 0, temp = 0;
	vector<int> princes = { 1, 2, 3, 4, 5, 6, 7, 8 };
	queue<int> Q;

	for (int i = 0; i < princes.size(); i++)
	{
		Q.push(princes[i]);
	}

	while (Q.size() != 1)
	{
		temp = Q.front();
		Q.pop();
		cnt++;
		if (cnt == K)
		{
			cnt = 0;
			continue;
		}
		Q.push(temp);
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No72();

	return 0;
}