#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 전력망을 둘로 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/86971
// 솔트룩스 코테 통과 못함...

int No()
{
    system_clock::time_point start = system_clock::now();

    int n = 9;
    vector<vector<int>> wires =
    { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };

    // 일일이 하나씩 전선 잘라보기
    vector<bool> ch_list(n, false);
    for (int i = 0; i < wires.size(); i++)
    {

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