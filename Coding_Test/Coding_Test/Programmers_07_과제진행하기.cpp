#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;
using namespace chrono;

// 과제 진행하기
// https://school.programmers.co.kr/learn/courses/30/lessons/176962

struct Edge
{
	string subject;
	int start_time = 0, need_time = 0;

	Edge(string s, string t, string n)
	{
		subject = s;
		start_time = s2i(t);
		need_time = stoi(n);
	}

	Edge(string s, int t, int n)
	{
		subject = s;
		start_time = t;
		need_time = n;
	}

	int s2i(string time)
	{
		int hour = stoi(time.substr(0, 2));
		int minute = stoi(time.substr(3, 5));
		return hour * 60 + minute;
	}

	bool operator<(const Edge a) const
	{
		return start_time < a.start_time;
	}
};

int No()
{
	system_clock::time_point start = system_clock::now();

	vector<vector<string>> plans =
	{ {"science", "12:40", "50"}, 
		{"music", "12:20", "40"}, 
		{"history", "14:00", "30"}, 
		{"computer", "12:30", "100"} };

	vector<string> answer;

	// 과목 정렬
	vector<Edge> info;
	for (int i = 0; i < plans.size(); i++)
	{
		info.push_back(Edge(plans[i][0], plans[i][1], plans[i][2]));
	}
	sort(info.begin(), info.end());

	// 잔여 과목 저장소
	stack<Edge> st;

	// 과목 처리하기
	int extra_time = 0;
	for (int i = 0; i < info.size() - 1; i++)
	{
		Edge cur = info[i];
		Edge next = info[i + 1];
		extra_time = next.start_time - cur.start_time;

		if (extra_time == 0)
		{
			answer.push_back(cur.subject);
			continue;
		}

		if (extra_time < cur.need_time)
		{
			st.push(Edge(cur.subject, cur.start_time, cur.need_time - extra_time));
		}
		else // extra_time >= cur.need_time
		{
			answer.push_back(cur.subject);
			extra_time -= cur.need_time;
			while (!st.empty() && extra_time != 0)
			{
				if (extra_time >= st.top().need_time)
				{
					extra_time -= st.top().need_time;
					answer.push_back(st.top().subject);
					st.pop();
				}
				else // extra_time < st.top().need_time
				{
					st.top().need_time -= extra_time;
					break;
				}
			}
		}
	}
	answer.push_back(info[info.size() - 1].subject);

	while (!st.empty())
	{
		answer.push_back(st.top().subject);
		st.pop();
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