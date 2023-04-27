#include <iostream>
#include <chrono>
#include <vector>

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