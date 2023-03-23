#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 봉우리
// 지도 정보가 N*N 격자판에 주어집니다.
// 각 격자에는 그 지역의 높이가 쓰여져 있다.
// 각 격자판의 숫자 중 자신의 상하좌우 숫자보다 큰 숫자는 봉우리 지역입니다.
// 봉우리 지역이 몇 개 있는지 알아내는 프로그램을 작성하세요.
// 격자의 가장자리는 0으로 초기화 되었다고 가정한다.
// 0 0 0 0 0 0 0
// 0 5 3 7 2 3 0
// 0 3 7 1 6 1 0
// 0 7 2 5 3 4 0
// 0 4 3 6 4 1 0
// 0 8 7 3 5 2 0
// 0 0 0 0 0 0 0
// 출력 : 10
int No47()
{
	system_clock::time_point start = system_clock::now();

	vector<vector<int>> map;
	map.push_back({ 5, 3, 7, 2, 3 });
	map.push_back({ 3, 7, 1, 6, 1 });
	map.push_back({ 7, 2, 5, 3, 4 });
	map.push_back({ 4, 3, 6, 4, 1 });
	map.push_back({ 8, 7, 3, 5, 2 });
	vector<int> di = { -1, 0, 1, 0 };
	vector<int> dj = { 0, 1, 0, -1 };

	// 이거는 풀 줄 안다! 다음 문제로!

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No47();
//
//	return 0;
//}