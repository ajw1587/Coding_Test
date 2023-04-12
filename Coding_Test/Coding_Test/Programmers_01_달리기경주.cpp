#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <map>

using namespace std;
using namespace chrono;

// 달리기 경주
// https://school.programmers.co.kr/learn/courses/30/lessons/178871
int No()
{
	system_clock::time_point start = system_clock::now();

	vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
	vector<string> callings = { "kai", "kai", "mine", "mine" };
	int idx = -1;
	string tmp;

	// 시간 초과
	//for (int i = 0; i < callings.size(); i++)
	//{
	//	string call = callings[i];

	//	auto iter = find(players.begin(), players.end(), call);
	//	if (iter == players.end()) continue;
	//	else
	//	{
	//		idx = iter - players.begin();
	//		players[idx] = players[idx - 1];
	//		players[idx - 1] = call;
	//	}
	//}

	map<string, int> name_rank;
	map<int, string> rank_name;
	for (int i = 0; i < players.size(); i++)
	{
		string name = players[i];
		int rank = i + 1;
		
		name_rank.insert(make_pair(name, rank));
		rank_name.insert(make_pair(rank, name));
	}

	for (int i = 0; i < callings.size(); i++)
	{
		string call = callings[i];
		int call_rank = name_rank[call];
		string front_player = rank_name[call_rank - 1];
		
		name_rank[call]--;
		name_rank[front_player]++;

		rank_name[call_rank] = front_player;
		rank_name[call_rank - 1] = call;
	}

	vector<string> answer;
	for (int i = 1; i <= players.size(); i++)
	{
		answer.push_back(rank_name[i]);
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