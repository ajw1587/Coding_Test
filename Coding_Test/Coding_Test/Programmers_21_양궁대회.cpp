#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ��� ��ȸ
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
            if (lion_info[i] > info[i]) continue;   // �̹� lion�� ���� ȹ�� �����Ѱ� PASS
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

    // 1. ����ġ ���� n��, �� ���� ���̾��� n��
    // 2. ���� ���
    //      2-1. k������ ����ġ�� a��, ���̾��� b���϶� �� ���� ���� ������ k���� ��������.
    //           ���� ��� ����ġ�� ȹ��!, �� ���� �� 0���� ��� ȹ�� ����!
    // 3. ���� ���� ���, ���� ��� ����ġ�� ���
    // ���� ����ġ�� n���� �� �� ����, ���̾��� �� ����

    //n = 5;
    //info = { 2,1,1,1,0,0,0,0,0,0,0 };
    //n = 1;
    //info = { 1,0,0,0,0,0,0,0,0,0,0 };
    n = 9;
    info = { 0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1 };

    //// DFS�� ����...?
    //// üũ����, �������� ����(answer)
    //vector<int> lion_info(info.size(), 0);
    //// count, lion_info
    //DFS(0, lion_info);
    //// �� �̱涧
    //if (answer.size() == 0) answer.push_back(-1);

    // �ٸ� Ǯ��
    for (int i = 10; i >= 0; i--) a[10 - i] = info[i];
    solve(0, 0);
    if (answer.empty()) answer.push_back(-1);

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