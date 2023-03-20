#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 0부터 9까지의 숫자가 표시된 카드
// A, B가 게임 참가
// 각각 카드를 늘어놓은 카드를 뒤집어서 포시된 숫자를 확인하는 것이 한 라운드 : 숫자 더 큰 사람이 Win
// 승점이 같은 경우, 제일 마지막에 이긴 사람이 최종 Win
int My_No21()
{
	system_clock::time_point start = system_clock::now();

	//vector<int> A = { 4, 5, 6, 7, 0, 1, 2, 3, 9, 8 };
	//vector<int> B = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> A = {9, 1, 7, 2, 6, 3, 0, 4, 8, 5};
	vector<int> B = {6, 3, 9, 2, 1, 0, 7, 4, 8, 5};
	vector<char> check(10, 'D');
	int a_cnt = 0, b_cnt = 0;

	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] > B[i])
		{
			check[i] = 'A';
			a_cnt++;
		}
		else if (B[i] > A[i])
		{
			check[i] = 'B';
			b_cnt++;
		}
	}

	bool draw_jug = false;
	if (a_cnt > b_cnt) cout << 'A' << endl;
	else if (b_cnt > a_cnt) cout << 'B' << endl;
	else
	{
		for (int i = check.size() - 1; i > -1; i--)
		{
			if (check[i] != 'D')
			{
				draw_jug = false;
				cout << check[i] << endl;
				break;
			}
			else
			{
				draw_jug = true;
				continue;
			}
		}
		if (draw_jug) cout << 'D' << endl;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;	// 206
	return 0;
}

int No21()
{
	system_clock::time_point start = system_clock::now();

	//vector<int> A = { 4, 5, 6, 7, 0, 1, 2, 3, 9, 8 };
	//vector<int> B = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	vector<int> A = { 9, 1, 7, 2, 6, 3, 0, 4, 8, 5 };
	vector<int> B = { 6, 3, 9, 2, 1, 0, 7, 4, 8, 5 };
	int a_cnt = 0, b_cnt = 0;
	char winner = 'D';

	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] > B[i])
		{
			a_cnt++;
			winner = 'A';
		}
		else if (B[i] > A[i])
		{
			b_cnt++;
			winner = 'B';
		}
	}

	if (a_cnt > b_cnt) cout << 'A' << endl;
	else if (b_cnt > a_cnt) cout << 'B' << endl;
	else
	{
		cout << winner << endl;
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;	// 63
	return 0;
}

//int main()
//{
//	My_No21();
//	No21();
//
//	return 0;
//}