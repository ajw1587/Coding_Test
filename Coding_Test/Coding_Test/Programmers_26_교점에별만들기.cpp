#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ������ �� �����
// https://school.programmers.co.kr/learn/courses/30/lessons/87377
// ��Ƴ�...?
int No()
{
    system_clock::time_point start = system_clock::now();

    vector<vector<int>> line =
    { {2, -1, 4}, {-2, -1, 4}, {0, -1, 1}, {5, -8, -12}, {5, 8, 12} };

    // 

    system_clock::time_point end = system_clock::now();
    microseconds micro = duration_cast<microseconds>(end - start);
    cout << "�ҿ� �ð� : " << micro.count() << endl;
    return 0;
}

int main()
{
    No();

    return 0;
}