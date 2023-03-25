#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 자연수 N이 주어지면 1부터 N까지의 원소를 갖는 집합의 부분집합을 모두 출력하시오.
// 전위순회 방식으로 출려하시오.
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
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No59();

	return 0;
}