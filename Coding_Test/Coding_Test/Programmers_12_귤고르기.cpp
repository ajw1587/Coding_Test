#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <map>
#include <typeinfo>

using namespace std;
using namespace chrono;

// 귤 고르기
// https://school.programmers.co.kr/learn/courses/30/lessons/138476

int answer = 2147000000;
vector<int> tangerine =
{ 1, 3, 2, 5, 4, 5, 2, 3 };

void DFS(int idx, int cnt, int s, vector<int> res, vector<int> ch_idx_tan, vector<int> ch_tan)
{
	if (idx == res.size())
	{
		if (answer > cnt)
		{
			answer = cnt;
		}
	}
	else
	{
		for (int i = s; i < tangerine.size(); i++)
		{
			if (ch_idx_tan[i] == 0)	// 사용한 tangerine의 idx 체크
			{
				ch_idx_tan[i] = 1;
				res[idx] = tangerine[i];
				
				if (ch_tan[tangerine[i]] == 0)	// 새로운 숫자면 cnt++
				{
					ch_tan[tangerine[i]]++;
					DFS(idx + 1, cnt + 1, i + 1, res, ch_idx_tan, ch_tan);
					ch_tan[tangerine[i]]--;
				}
				else  // ch_tan[tangerine[i]] != 0
				{
					ch_tan[tangerine[i]]++;
					DFS(idx + 1, cnt, i + 1, res, ch_idx_tan, ch_tan);
					ch_tan[tangerine[i]]--;
				}

				ch_idx_tan[i] = 0;
			}
		}
	}
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}

int No()
{
	system_clock::time_point start = system_clock::now();
	int k = 6;

	sort(tangerine.begin(), tangerine.end());

	vector<int> res(k, 0);
	vector<int> ch_tan(tangerine.size(), 0);		// 숫자별 사용 횟수
	vector<int> ch_idx_tan(tangerine.size(), 0);	// tan에서 사용한 인덱스 체크
	DFS(0, 0, 0, res, ch_idx_tan, ch_tan);

	map<int, int> tmp;
	for (int i = 0; i < tangerine.size(); i++)
	{
		tmp[tangerine[i]]++;
	}

	vector<pair<int, int>> vtmp;
	for (pair<int, int> t : tmp)
	{
		vtmp.push_back(make_pair(t.first, t.second));
	}

	sort(vtmp.begin(), vtmp.end(), cmp);

	// 정답 구해주기
	int sa = k;
	int answer = 0;
	for (int i = 0; i < sa; i++)
	{
		if (k <= 0) break;
		else
		{
			k -= vtmp[i].second;
			answer++;
		}
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