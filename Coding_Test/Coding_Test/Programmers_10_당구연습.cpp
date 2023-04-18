#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 당구 연습
// https://school.programmers.co.kr/learn/courses/30/lessons/169198

int No()
{
	system_clock::time_point start = system_clock::now();

	// m : 가로, n : 세로
	int m = 10, n = 10;
	int startX = 3, startY = 7;
	vector<vector<int>> balls =
	{ {7, 7}, {2, 7}, {7, 3} };

	vector<int> answer;

	// 상하좌우 좌표 미러링하기
	vector<int> ball;
	int tmp = 2147000000;
	int res = 2147000000;
	int x = 0, y = 0;
	for (int i = 0; i < balls.size(); i++)
	{
		ball = balls[i];
		res = 2147000000;
		// 상
		x = ball[0] - startX;
		y = n + (n - ball[1]) - startY;
		if (x != 0)
		{
			tmp = pow(x, 2) + pow(y, 2);
			if (res > tmp) res = tmp;
		}
		else if(ball[1] < startY)
		{
			tmp = pow(x, 2) + pow(y, 2);
			if (res > tmp) res = tmp;
		}

		// 하
		x = ball[0] - startX;
		y = startY - -1 * ball[1];
		if (x != 0)
		{
			tmp = pow(x, 2) + pow(y, 2);
			if (res > tmp) res = tmp;
		}
		else if (ball[1] > startY)
		{
			tmp = pow(x, 2) + pow(y, 2);
			if (res > tmp) res = tmp;
		}

		// 좌
		x = startX - -1 * ball[0];
		y = ball[1] - startY;
		if (y != 0)
		{
			tmp = pow(x, 2) + pow(y, 2);
			if (res > tmp) res = tmp;
		}
		else if (ball[0] > startX)
		{
			tmp = pow(x, 2) + pow(y, 2);
			if (res > tmp) res = tmp;
		}

		// 우
		x = m + (m - ball[0]) - startX;
		y = ball[1] - startY;
		if (y != 0)
		{
			tmp = pow(x, 2) + pow(y, 2);
			if (res > tmp) res = tmp;
		}
		else if (ball[0] < startX)
		{
			tmp = pow(x, 2) + pow(y, 2);
			if (res > tmp) res = tmp;
		}

		answer.push_back(res);
	}

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "소요 시간 : " << micro.count() << endl;
	return 0;
}

int main()
{
	No();

	return 0;
}