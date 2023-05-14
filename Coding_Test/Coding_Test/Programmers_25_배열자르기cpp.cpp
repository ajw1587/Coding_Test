#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// n^2 배열 자르기 C++
// https://school.programmers.co.kr/learn/courses/30/lessons/87390

int No()
{
    system_clock::time_point start = system_clock::now();

    vector<int> answer;
    int n = 3, left = 2, right = 5;

    int row = 0, col = 0, tmp = 0;
    for (int i = left; i <= right; i++)
    {
        row = i / n;
        col = i % n;
        tmp = (row >= col) ? row + 1 : col + 1;
        answer.push_back(tmp);
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