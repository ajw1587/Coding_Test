#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���츮
// ���� ������ N*N �����ǿ� �־����ϴ�.
// �� ���ڿ��� �� ������ ���̰� ������ �ִ�.
// �� �������� ���� �� �ڽ��� �����¿� ���ں��� ū ���ڴ� ���츮 �����Դϴ�.
// ���츮 ������ �� �� �ִ��� �˾Ƴ��� ���α׷��� �ۼ��ϼ���.
// ������ �����ڸ��� 0���� �ʱ�ȭ �Ǿ��ٰ� �����Ѵ�.
// 0 0 0 0 0 0 0
// 0 5 3 7 2 3 0
// 0 3 7 1 6 1 0
// 0 7 2 5 3 4 0
// 0 4 3 6 4 1 0
// 0 8 7 3 5 2 0
// 0 0 0 0 0 0 0
// ��� : 10
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

	// �̰Ŵ� Ǯ �� �ȴ�! ���� ������!

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

//int main()
//{
//	No47();
//
//	return 0;
//}