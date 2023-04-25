#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ��� ��ȸ
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
        // apeach_sum, lion_sum ���ϱ�s
        if (answer.empty())
        {
            answer = lion_info;
            lion_sum_tmp = lion_sum - apeach_sum;
            return;
        }
        if (lion_sum > apeach_sum)
        {
            // ���� ������ �� ���� ȹ���ߴ��� Ȯ��
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
            if (lion_info[i] > info[i]) continue;   // �̹� lion�� ���� ȹ�� �����Ѱ� PASS
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

    // 1. ����ġ ���� n��, �� ���� ���̾��� n��
    // 2. ���� ���
    //      2-1. k������ ����ġ�� a��, ���̾��� b���϶� �� ���� ���� ������ k���� ��������.
    //           ���� ��� ����ġ�� ȹ��!, �� ���� �� 0���� ��� ȹ�� ����!
    // 3. ���� ���� ���, ���� ��� ����ġ�� ���
    // ���� ����ġ�� n���� �� �� ����, ���̾��� �� ����

    n = 5;
    info = { 2,1,1,1,0,0,0,0,0,0,0 };
    // 0,2,2,0,1,0,0,0,0,0,0

    // info ���� �ٲ��ֱ�
    vector<int> r_info;
    for (int i = info.size() - 1; i >= 0; i--)
    {
        r_info.push_back(info[i]);
    }

    // DFS�� ����...?
    // üũ����, �������� ����(answer)
    //vector<bool> ch(info.size(), true);
    vector<int> lion_info(info.size(), 0);
    //for (int i = 0; i < info.size(); i++)
    //{
    //    if(info[i] != 0) apeach_sum += (10 - i);
    //}

    // ��, lion_info, ch
    DFS(0, 0, 0, lion_info);

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