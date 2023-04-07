#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 동전교환
// 다음과 같이 여러 단위의 동전들이 주어져 있을때 거스름돈을 가장 적은 수의 동전으로 교환
// 해주려면 어떻게 주면 되는가 ? 각 단위의 동전은 무한정 쓸 수 있다.
int No100()
{
	system_clock::time_point start = system_clock::now();

	int coin_N = 3;
	vector<int> coin = { 1, 2, 5 };
	int money = 15;

	vector<int> res(money + 1, 21476000000);
	res[0] = 0;
	for (int i = 0; i < coin.size(); i++)
	{
		int c = coin[i];
		for (int j = c; j < res.size(); j++)
		{
			res[j] = min(res[j], res[j - c] + 1);
		}
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No100();

	return 0;
}