#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// 양궁 대회
// https://school.programmers.co.kr/learn/courses/30/lessons/92342
int n = 0;
int lion_sum_tmp = 0;
vector<int> info;
vector<int> answer;

void sum_check(int& lion_sum, int& apeach_sum, vector<int> lion_info)
{
    for (int i = 0; i < info.size(); i++)
    {
        if (info[i] >= lion_info[i] && info[i] != 0) apeach_sum += (10 - i);
        else if (info[i] < lion_info[i]) lion_sum += (10 - i);
    }
}

void DFS(int cnt, vector<int>& lion_info)
{
    if (cnt >= n)
    {
        int lion_sum = 0, apeach_sum = 0;
        sum_check(lion_sum, apeach_sum, lion_info);
        if (lion_sum > apeach_sum)
        {
            int lion_apeach = lion_sum - apeach_sum;
            if (lion_apeach > lion_sum_tmp)
            {
                answer = lion_info;
                lion_sum_tmp = lion_apeach;
            }
            else if (lion_apeach == lion_sum_tmp)
            {
                for (int i = lion_info.size() - 1; i >= 0; i--)
                {
                    if (answer[i] < lion_info[i])
                    {
                        answer = lion_info;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < lion_info.size(); i++)
        {
            if (lion_info[i] > info[i]) continue;   // 이미 lion이 점수 획득 가능한건 PASS
            lion_info[i]++;
            DFS(cnt + 1, lion_info);
            lion_info[i]--;
        }
    }
}

int a[11];
int r[11];
int ans;

void solve(int cnt, int idx) {
    if (cnt == n) {
        for (int i = 0; i < info.size(); i++)
            cout << r[i] << " ";
        cout << endl;
        int asum = 0;
        int rsum = 0;
        for (int i = 0; i <= 10; i++) {
            if (a[i] == r[i] && a[i] == 0) continue;
            if (r[i] > a[i]) rsum += i;
            else asum += i;
        }
        if (ans < rsum - asum) {
            ans = rsum - asum;
            answer.clear();
            for (int i = 10; i >= 0; i--) {
                answer.push_back(r[i]);
            }
        }
    }
    for (int i = idx; i <= 10; i++) {
        if (a[i] >= r[i]) {
            r[i]++;
            solve(cnt + 1, i);
            r[i]--;
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

    //n = 5;
    //info = { 2,1,1,1,0,0,0,0,0,0,0 };
    //n = 1;
    //info = { 1,0,0,0,0,0,0,0,0,0,0 };
    n = 9;
    info = { 0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1 };

    //// DFS로 접근...?
    //// 체크벡터, 저장해줄 벡터(answer)
    //vector<int> lion_info(info.size(), 0);
    //// count, lion_info
    //DFS(0, lion_info);
    //// 못 이길때
    //if (answer.size() == 0) answer.push_back(-1);

    // 다른 풀이
    for (int i = 10; i >= 0; i--) a[10 - i] = info[i];
    solve(0, 0);
    if (answer.empty()) answer.push_back(-1);

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