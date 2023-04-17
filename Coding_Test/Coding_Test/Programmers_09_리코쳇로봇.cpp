#include <iostream>
#include <chrono>
#include <vector>
#include <typeinfo>
#include <queue>

using namespace std;
using namespace chrono;

// ������ �κ�
// https://school.programmers.co.kr/learn/courses/30/lessons/169199
int No()
{
	system_clock::time_point start = system_clock::now();
	int answer = 2147000000;

	// R : �κ� ��ġ
	// D : ��
	vector<string> board =
	{ "...D..R", 
	  ".D.G...", 
	  "....D.D", 
	  "D....D.", 
	  "..D...." };

	// �����¿�
	vector<int> di = { -1, 1, 0, 0 };
	vector<int> dj = { 0, 0, -1, 1 };

	// �� �ٲ��ֱ� �� ������ġ, ������ġ �������ֱ�
	vector<vector<char>> map;
	vector<vector<int>> ch_map(board.size(), vector<int>(board[0].size(), 2147000000));
	pair<int, int> S, G;
	vector<char> tmp;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 'R') S = make_pair(i, j);
			else if (board[i][j] == 'G') G = make_pair(i, j);
			else if (board[i][j] == 'D') ch_map[i][j] = 2146999999;
			tmp.push_back(board[i][j]);
		}
		map.push_back(tmp);
		tmp.clear();
	}
	ch_map[S.first][S.second] = 0;

	// ��� ã��
	queue<pair<int, int>> q;
	q.push(S);
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int i = 0;
		int xx, yy;
		for (i = 0; i < 4; i++)
		{
			xx = x;
			yy = y;
			while (1)
			{
				xx += di[i];
				yy += dj[i];
				if (xx < 0 || yy < 0 || xx >= map.size() || yy >= map[0].size()) break;
				if (map[xx][yy] == 'D') break;
			}
			xx -= di[i];
			yy -= dj[i];

			if (ch_map[xx][yy] != 2147000000) continue;
			ch_map[xx][yy] = min(ch_map[xx][yy], ch_map[x][y] + 1);
			q.push(make_pair(xx, yy));
		}
	}

	answer = ch_map[G.first][G.second];

	system_clock::time_point end = system_clock::now();
	microseconds micro = duration_cast<microseconds>(end - start);
	cout << "�ҿ� �ð� : " << micro.count() << endl;
	return 0;
}

int main()
{
	No();

	return 0;
}