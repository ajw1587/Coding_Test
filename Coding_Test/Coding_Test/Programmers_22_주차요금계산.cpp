#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;
using namespace chrono;

// 주차 요금 계산
// https://school.programmers.co.kr/learn/courses/30/lessons/92341
int No()
{
    system_clock::time_point start = system_clock::now();

    vector<int> answer;
    vector<int> fees =
    { 180, 5000, 10, 600 };
    vector<string> records =
    { "05:34 5961 IN",
      "06:00 0000 IN",
      "06:34 0000 OUT",
      "07:59 5961 OUT",
      "07:59 0148 IN",
      "18:59 0000 IN",
      "19:09 0148 OUT",
      "22:59 5961 IN",
      "23:00 5961 OUT" };
    //vector<int> fees = { 1, 461, 1, 10 };
    //vector<string> records = { "00:00 1234 IN" };

    // 정리하기
    map<int, queue<pair<string, int>>> ch;
    for (int i = 0; i < records.size(); i++)
    {
        int time = stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2));
        int car_num = stoi(records[i].substr(6, 4));
        string in_out = records[i].substr(11, -1);

        ch[car_num].push(make_pair(in_out, time));
    }

    // 정리된 records로 계산하기
    auto iter = ch.begin();
    while (iter != ch.end())
    {
        int tmp = 0;
        int start = 0;
        int end = 0;
        int total_time = 0;
        while (!(iter->second.empty()))
        {
            string status = iter->second.front().first;
            if (status == "IN" && iter->second.size() != 1)
            {
                start = iter->second.front().second;
                iter->second.pop();
                continue;
            }
            else  if (status == "OUT")
            {
                end = iter->second.front().second;
                total_time += end - start;
                start = 0;
                end = 0;
                iter->second.pop();
            }
            else if(status == "IN")
            {
                start = iter->second.front().second;
                total_time += (1439 - start);
                iter->second.pop();
            }
        }
        if (total_time <= fees[0])
        {
            answer.push_back(fees[1]);
        }
        else  // total_time > fees[0]
        {
            float tmp_time = total_time - fees[0];
            answer.push_back(fees[1] + ceil(tmp_time / fees[2]) * fees[3]);
        }

        iter++;
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