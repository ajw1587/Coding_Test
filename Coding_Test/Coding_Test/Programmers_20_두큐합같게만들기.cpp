#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace chrono;

// 두 큐 합 같게 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/118667
int No()
{
    system_clock::time_point start = system_clock::now();

    int answer = 0;    // 2
    vector<int> queue1 =
    { 3, 2, 7, 2 };
    vector<int> queue2 =
    { 4, 6, 5, 1 };

    // queue로 옮겨주기, 전체 합 구하기
    int total_sum = 0;
    int que1_sum = 0, que2_sum = 0;
    queue<int> que1;
    queue<int> que2;
    for (int i = 0; i < queue1.size(); i++)
    {
        que1.push(queue1[i]);
        que2.push(queue2[i]);

        que1_sum += queue1[i];
        que2_sum += queue2[i];
        total_sum += (queue1[i] + queue2[i]);
    }

    // 체크해주기!
    if (total_sum % 2 != 0) return -1;

    for (int i = 0; i < 600000; i++)
    {
        if (que1.empty() || que2.empty())
        {
            answer = -1;
            break;
        }

        if (que1_sum > que2_sum)
        {
            que1_sum -= que1.front();
            que2_sum += que1.front();
            que2.push(que1.front());
            que1.pop();
            answer++;
        }
        else if (que1_sum < que2_sum)
        {
            que2_sum -= que2.front();
            que1_sum += que2.front();
            que1.push(que2.front());
            que2.pop();
            answer++;
        }
    }
    if (answer == 600000) answer = -1;

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