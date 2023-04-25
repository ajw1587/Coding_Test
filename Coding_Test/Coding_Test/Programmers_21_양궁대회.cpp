#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 양궁 대회
// https://school.programmers.co.kr/learn/courses/30/lessons/92342
int n = 0;
//int apeach_sum = 0;
int lion_sum_tmp = 0;
vector<int> info;
vector<int> answer;

void DFS(int lion_sum, int apeach_sum, int cnt, vector<int> &lion_info)
{
    if (cnt >= n)
    {
        // apeach_sum, lion_sum 구하기s
        if (answer.empty())
        {
            answer = lion_info;
            lion_sum_tmp = lion_sum - apeach_sum;
            return;
        }
        if (lion_sum > apeach_sum)
        {
            // 적은 점수를 더 많이 획득했는지 확인
            for (int i = answer.size() - 2; i >= 0; i--)
            {
                if (lion_info[i] == 0 && answer[i] == 0) continue;
                if (lion_info[i] >= answer[i] && (lion_sum - apeach_sum) > lion_sum_tmp)
                {
                    answer = lion_info;
                    lion_sum_tmp = lion_sum;
                }
            }
        }
        return;
    }
    else
    {
        for (int i = 0; i < lion_info.size(); i++)
        {
            if (lion_info[i] > info[i]) continue;   // 이미 lion이 점수 획득 가능한건 PASS
            lion_info[i]++;
            if(lion_info[i] <= info[i]) DFS(lion_sum, apeach_sum + 10 - i, cnt + 1, lion_info);
            else DFS(lion_sum + 10 - i, apeach_sum, cnt + 1, lion_info);
            lion_info[i]--;
        }
    }
}

int No()
{
    system_clock::time_point start = system_clock::now();

    // 1. 어피치 먼저 n발, 그 다음 라이언이 n발
    // 2. 점수 계산
    //      2-1. k점수를 어피치가 a발, 라이언이 b발일때 더 많이 맞춘 선수가 k점을 가져간다.
    //           같을 경우 어피치가 획득!, 두 선수 다 0발일 경우 획득 실패!
    // 3. 최종 점수 계산, 같을 경우 어피치가 우승
    // 현재 어피치는 n발을 다 쏜 상태, 라이언이 쏠 차례

    n = 5;
    info = { 2,1,1,1,0,0,0,0,0,0,0 };
    // 0,2,2,0,1,0,0,0,0,0,0

    // info 순서 바꿔주기
    vector<int> r_info;
    for (int i = info.size() - 1; i >= 0; i--)
    {
        r_info.push_back(info[i]);
    }

    // DFS로 접근...?
    // 체크벡터, 저장해줄 벡터(answer)
    //vector<bool> ch(info.size(), true);
    vector<int> lion_info(info.size(), 0);
    //for (int i = 0; i < info.size(); i++)
    //{
    //    if(info[i] != 0) apeach_sum += (10 - i);
    //}

    // 합, lion_info, ch
    DFS(0, 0, 0, lion_info);

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