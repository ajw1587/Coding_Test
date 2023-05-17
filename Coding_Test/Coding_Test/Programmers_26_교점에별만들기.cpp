#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 교점에 별 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/87377
// 어렵네...?

// Ax + By + E = 0
// Cx + Dy + F = 0
void get_dot(vector<int> dot1, vector<int> dot2)
{
    int A = dot1[0], B = dot1[1], E = dot1[2];
    int C = dot2[0], D = dot2[1], F = dot2[2];
}

int No()
{
    system_clock::time_point start = system_clock::now();

    vector<vector<int>> line =
    { {2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12} };

    // 

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