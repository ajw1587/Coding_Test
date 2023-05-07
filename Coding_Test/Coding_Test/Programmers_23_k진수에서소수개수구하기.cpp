#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// k진수에서 소수 개수 구하기
// https://school.programmers.co.kr/learn/courses/30/lessons/92335
int No()
{
    system_clock::time_point start = system_clock::now();

    int n = 437674;
    int k = 3;

    // k 진수로 바꿔주기


    // 0을 기준으로 값 나눠주기

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