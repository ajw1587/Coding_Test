#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// �ڿ��� N�� �־����� 1���� N������ ���Ҹ� ���� ������ �κ������� ��� ����Ͻÿ�.
// ������ȸ ������� ����Ͻÿ�.
// ex)
// N = 3
// 1 2 3 
// 1 2
// 1 3
// 1
// 2 3
// 2
// 3
//

void D(int L, int N, vector<int>& check)
{
	if (L == N + 1)
	{
		for (int i = 1; i <= N; i++)
		{
			if (check[i] == 1) cout << i << ' ';
		}
		cout << endl;
	}
	else
	{
		check[L] = 1;
		D(L + 1, N, check);
		check[L] = 0;
		D(L + 1, N, check);
	}
}

int No59()
{
	system_clock::time_point start = system_clock::now();

	int N = 3;
	vector<int> check(N + 1, 0);

	D(1, N, check);

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No59();

	return 0;
}