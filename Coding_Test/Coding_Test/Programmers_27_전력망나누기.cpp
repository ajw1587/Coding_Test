#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

// ���¸��� �ѷ� ������
// https://school.programmers.co.kr/learn/courses/30/lessons/86971

int No()
{
    system_clock::time_point start = system_clock::now();

    int n = 9;
    vector<vector<int>> wires =
    { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };

    // ������ �ϳ��� ���� �߶󺸱�
    vector<bool> ch_list(n, false);
    vector<vector<int>> tmp;
    for (int i = 0; i < wires.size(); i++)
    {
        for (int j = 0; j < wires.size(); j++)
        {
            if (j == i) continue;
            tmp.push_back(wires[j]);
        }

        tmp.clear();
    }

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