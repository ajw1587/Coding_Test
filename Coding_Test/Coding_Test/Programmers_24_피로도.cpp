#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 피로도
// https://school.programmers.co.kr/learn/courses/30/lessons/87946

int No()
{
    system_clock::time_point start = system_clock::now();

    int k = 80;
    vector<vector<int>> dungeons =
    { {80,20} ,{50,40},{30,10} };

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