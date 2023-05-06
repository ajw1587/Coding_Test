#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <map>
#include <stack>

using namespace std;
using namespace chrono;

// 주차 요금 계산
// https://school.programmers.co.kr/learn/courses/30/lessons/92341
int No()
{
    system_clock::time_point start = system_clock::now();

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

    map<int, stack<pair<string, int>>> ch;
    for (int i = 0; i < records.size(); i++)
    {
        int time = stoi(records[i].substr(0, 2)) * 60 + stoi(records[i].substr(3, 2));
        int car_num = stoi(records[i].substr(6, 4));
        string in_out = records[i].substr(11, -1);

        ch[car_num].push(make_pair())
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