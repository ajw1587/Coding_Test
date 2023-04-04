#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 최대 선 연결하기
// 왼쪽의 번호와 오른쪽의 번호가 있는 그림에서 같은 번호끼리 선으로 연결하려고 합니다. 
// 왼쪽번호는 무조건 위에서부터 차례로 1부터 N까지 오름차순으로 나열되어 있습니다.
// 오른쪽의 번호 정보가 위부터 아래 순서로 주어지만 서로 선이 겹치지 않고
// 최대 몇 개의 선을 연결할 수 있는 지 구하는 프로그램을 작성하세요.

int No95()
{
	system_clock::time_point start = system_clock::now();

	int N = 10;
	vector<int> numbers = { 4, 1, 2, 3, 9, 7, 5, 6, 10, 8 };
	vector<int> res(N, 1);

	res[0] = 1;
	for (int i = 1; i < res.size(); i++)	// res
	{
		for (int j = i; j > 0; j--)
		{
			if (numbers[i] > numbers[j] && res[i] < res[j] + 1)
			{
				res[i] = res[j] + 1;
			}
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No95();

	return 0;
}