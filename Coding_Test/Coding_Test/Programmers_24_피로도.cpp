#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
using namespace chrono;

// 피로도
// https://school.programmers.co.kr/learn/courses/30/lessons/87946

vector<vector<int>> dg;
int K = 0, answer = 0;
vector<bool> ch;

void DFS(int answer_cnt, int kk)
{
    if (kk < 0) return;

    answer = max(answer, answer_cnt);

    for (int i = 0; i < ch.size(); i++)
    {
        if (!ch[i] && kk >= dg[i][0])
        {
            ch[i] = true;
            DFS(answer_cnt + 1, kk - dg[i][1]);
            ch[i] = false;
        }
    }
}

int No()
{
    system_clock::time_point start = system_clock::now();

    int k = 80;
    vector<vector<int>> dungeons =
    { {80,20}, {50,40}, {30,10} };

    K = k;
    dg = dungeons;
    for (int i = 0; i < dg.size(); i++) ch.push_back(false);

    // DFS로 접근하기
    DFS(0, K);

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