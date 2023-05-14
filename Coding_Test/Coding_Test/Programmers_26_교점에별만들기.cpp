#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 교점에 별 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/87377
int No()
{
    system_clock::time_point start = system_clock::now();

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